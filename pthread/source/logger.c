int header=1;
void logger(multiReturn mr){
       


      FILE *file; // points to file
      char filename[40] ="log/log.txt";
          
      if((file= fopen(filename,"a"))==NULL) //open the file "a" = add content at the end of file
      {
        printf("\nCan't open the file log.txt!\n\n "); 
      }else{
        // log params
        fprintf(file,"%d;%d;%d;%d;%d;%d;%f;%s;%d\n",(int)timestamp,print,method,m,n,p,mr.time,mr.type,numOfProc); 
      }
      fclose(file); // close file
      
      
      if(header==1){
          printf("\nYou will find the results in /log/log.txt\n");
          // print all important parameters to screen
          printf("\ntimestamp: %d print option: %d method: %d\nm: %d  n: %d  p: %d \n",(int)timestamp,print,method,m,n,p);  
          printf("Number of Processors: %d\n\n",numOfProc);
          header=0;// only once the header is printed
      }
      printf("%s: %fs\n",mr.type,mr.time);
      
}
