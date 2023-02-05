#include <stdio.h>

/*
 a = 10;

 &a Denotes Pointer of 'a'
 *a Denotes Value at Pointer 'a'

 */

void printNum(int n)
{
    printf("%d\n",n);
}

void changeToZero(int **numAddressesAddress)
{
    //*numAddress = 0;
    //int *ptrOfNum = numAddressesAddress;

    int **p = numAddressesAddress;

    **p = 60;

    //**numAddressesAddress = 0;
}

int main()
{
    printf("Hello World\n");
    int num=70;

    int *ptrOfNum = &num;
    int **ptrOfPtrOfNum = &ptrOfNum;

    changeToZero(ptrOfPtrOfNum);

    printf("ptr Val : %d",num);


}
