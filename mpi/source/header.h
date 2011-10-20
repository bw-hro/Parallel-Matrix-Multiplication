// datatype for matrices
typedef struct{
    char name[10];
    int rows;
    int cols; 
    int **matrix;  
} matrix;

//matrix A,B,C,D,E,F;

// datatype for the result of matrixmultiplication
typedef struct{
    char type[10];
    double time;    
} multiReturn;

int col, row, startrow, add, m, n, p, print, method; //these vars are in all functions availble
int numOfProc; // num of processors e.g. atlas = 8
time_t timestamp; 

int size, rank;
int i, j, k;

int MASTER = 0;
int MTYPE_FROM_MASTER = 1;
int MTYPE_FROM_SLAVE = 2;
MPI_Status status;

