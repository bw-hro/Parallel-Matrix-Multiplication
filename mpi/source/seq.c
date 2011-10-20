multiReturn matrixMultiSEQ(matrix matrixA, matrix matrixB, matrix matrixC){
 printf("\nStart sequential multiplication ... \n");
 //double time1=omp_get_wtime();
 double time1=MPI_Wtime();
 for(row=0;row<matrixA.rows;row++){
    for(col=0;col<matrixB.cols;col++){
    	int tempSum=0;
      for(add=0;add<matrixA.cols;add++){
        tempSum += matrixA.matrix[row][add] * matrixB.matrix[add][col];
      }
      matrixC.matrix[row][col] = tempSum; 
    }
  }
  //double time2=omp_get_wtime();
  double time2=MPI_Wtime();
  printf("finished\n\n");

  multiReturn mr = {"SEQ",time2-time1};
  
  return mr;
}
