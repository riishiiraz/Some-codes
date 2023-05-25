#include <stdio.h>
#include <stdlib.h>

#define prt(n) printf("%d\n", n)

int main()
{

    int *ptr;

    ptr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        *ptr = (69+i);
        ptr++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Item at %d = %d\n", i, *--ptr);
    }
    //printf("Value : %d", ptr[0]);
}