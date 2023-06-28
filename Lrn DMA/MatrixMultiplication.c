#include <stdio.h>
#include <stdlib.h>

struct  matrix
{
    int **data, row,column;
};


int** input(int r, int c){


    int **M = (int**)malloc(sizeof(int*)*r);        // Initialising The 2D Array (Matrix)
    for (int i=0;i<r;i++)                           // Initialising The 1D Array (Rows)
        M[i] = (int*)malloc(sizeof(int)*c);


    for (int i = 0; i < r; i++){
        printf("\nEnter %d column :",i+1);
        for (int j = 0; j < c; j++){
            scanf("%d", &M[i][j]);
        }
    }
    return M;
}

void display(struct matrix M){

    for (int i = 0; i < M.row; i++){
        for (int j = 0; j < M.column; j++){
            printf(" %d ",M.data[i][j]);
        }
        printf("\n");
    }
}

int **multi(struct matrix M1 ,struct matrix M2){

    int **M = (int**)malloc(sizeof(int*)*M1.row);       // Initialising The 2D Array (Matrix)
    for (int i=0;i<M1.row;i++)                          // Initialising The 1D Array (Rows)
        M[i] = (int*)calloc(sizeof(int),M2.column);

    for (int i=0;i<M1.row ; i++){
        for (int j=0 ; j<M2.column ; j++){
            M[i][j]=0;

            for (int k=0 ; k<M1.column ; k++){
                M[i][j]+=(M1.data[i][k]*M2.data[k][j]);
            }
        }
    }
    return M;


}

int main()
{
    int r1 = 2 , c1 = 3, r2 = 3 , c2 = 2;

    struct matrix M1,M2 , PROD;

    M1.data = input(r1,c1);
    M1.row=r1;
    M1.column = c1;

    M2.data = input(r2,c2);
    M2.row=r2;
    M2.column = c2;

    PROD.row = M1.row;
    PROD.column = M2.column;
    PROD.data = multi(M1,M2);

    printf("Matrix 1 : \n");
    display(M1);

    printf("Matrix 2 : \n");
    display(M2);

    printf("The PRoduct is : \n");
    display(PROD);
}