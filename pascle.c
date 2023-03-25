#include <stdio.h>

long long factorial(int n){
    if(n<=1)
        return 1;
    
    return n * factorial(n-1);
}

long long nCr( int n , int r){
    return factorial(n) / (factorial(r) * factorial(n-r));
}

void pascle(int n){

    int i,j;

    for (i = 0 ; i<n ; i++){
        
        for ( j=(n-i) ; j>0 ; j-- ){
            printf(" ");
        }

        for( j=0 ; j<=i ; j++ ){
            printf("%ld ",nCr(i,j));
        }

        printf("\n");
    }
}


int main(){
    pascle(5);
}

/*
Output :
             1 
            1 1
           1 2 1
          1 3 3 1
         1 4 6 4 1
*/
