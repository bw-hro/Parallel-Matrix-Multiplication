// datatype for matrices
typedef struct{
    char name[10];
    int rows;
    int cols; 
    int **matrix;  
} matrix;

// datatype for the result of matrixmultiplication
typedef struct{
    char type[10];
    double time;    
} multiReturn;

int col, row, add, m, n, p, print, method; //these vars are in all functions availble
int numOfProc; // num of processors e.g. atlas = 8
time_t timestamp; 
