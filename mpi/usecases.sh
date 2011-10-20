#!/bin/sh
echo "
Welcome these script executes a line of usecases...
 
 A[n][n]*B[n]n[]=C[n][n]
"

rep=3 #number of repetitions for each usecase

# All testcases a[n][n]*b[n]n[]=c[n][n] print no matrices to screen or file cause of "0"
for dimension in 500 1000 2000
  do
  for processors in 4 8 16 32
  do
	    i=1
	    while [ $i -le $rep ]
	    do
	      echo " execute mpirun -np "$processors" ./prog "$dimension $dimension $dimension 0 0
		  mpirun -np $processors -machinefile machinefile.sirius prog $dimension $dimension $dimension 0 0 > /dev/null #print nothing to screen
		  sleep 1
		  i=$(($i + 1)) # = i++
	    done
	    echo""
  done		
done

echo "
finished read log.txt for results
"
