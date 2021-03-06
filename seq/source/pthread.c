typedef struct{
  int tid;
  matrix* matrixA;
  matrix* matrixB; 
  matrix* matrixC;
}thread_args; 

pthread_mutex_t mutex;

int colArr[8];
int addArr[8];
int tempSum[8];

void *threadFunction(void *data){
    thread_args* args=(thread_args*) data; ;
    
    matrix A=*args->matrixA;
    matrix B=*args->matrixB;
    matrix C=*args->matrixC;
    
    int numOfIters=A.rows/numOfProc;
    int lastNumOfIters=numOfIters+A.rows-numOfIters*numOfProc;
    int startIters = numOfIters*args->tid;
    
    if(args->tid==numOfProc-1){
        numOfIters=lastNumOfIters;
    }
    printf("Thread: %d Anzahl: %d %d %d\n",args->tid, numOfIters,startIters, startIters+numOfIters);
    
    for(row=startIters;row<startIters+numOfIters;row++){
        for(colArr[args->tid]=0;colArr[args->tid]<B.cols;colArr[args->tid]++){
    	tempSum[args->tid]=0;
            for(addArr[args->tid]=0;addArr[args->tid]<A.cols;addArr[args->tid]++){
                tempSum[args->tid] += A.matrix[row][addArr[args->tid]] * B.matrix[addArr[args->tid]][colArr[args->tid]];
            }
            pthread_mutex_lock(&mutex);
            C.matrix[row][colArr[args->tid]] = tempSum[args->tid]; 
	    pthread_mutex_unlock(&mutex);
        }
    }
    
    pthread_exit(NULL);

}


multiReturn matrixMultiPTH(matrix matrixA, matrix matrixB, matrix matrixC){
 printf("\nStart sequential multiplication ... \n");
 double time1=omp_get_wtime();
  
  int t;
  pthread_t threads[numOfProc];
  thread_args args[numOfProc];
 
  pthread_mutex_init(&mutex,NULL);
  
  for(t=0;t<numOfProc;t++){
        args[t].tid=t;
        args[t].matrixA=&matrixA;
        args[t].matrixB=&matrixB;
        args[t].matrixC=&matrixC;
		pthread_create(&threads[t], NULL, threadFunction, (void *) &args[t]);	
  }
  for(t=0;t<numOfProc;t++){
		pthread_join(threads[t], NULL);
  }
  printf("Fertig...\n");
  
  double time2=omp_get_wtime();
  printf("finished\n\n");
  
  multiReturn mr = {"PTHREAD",time2-time1};
  
  return mr;
}


