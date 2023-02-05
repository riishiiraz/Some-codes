#include <stdio.h>

int main()
{
    int x=20;

    //int spc = x-1;
    //int chr = 1;

    int spc = 0;
    int chr = (x*2)-1;

    for (int i=0 ; i<x ; i++)
    {
        for (int j=0 ; j<spc ; j++)
        {
            printf(" ");
        }

        for (int j=0 ; j<chr ; j++)
        {
            printf("*");
        }

        printf("\n");

        spc++;
        chr-=2;

    }


}

/*

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

 */
