#include <stdio.h>

void printNum(int n)
{
    printf("%d\n",n);
}

void changeToZero(int &numAddress) //Only Support in C++ | Not in C Language
{
    numAddress = 0;
}

int main()
{
    printf("Hello World\n");
    int num=70;

    changeToZero(num);

    printf("ptr Val : %d",num);


}

