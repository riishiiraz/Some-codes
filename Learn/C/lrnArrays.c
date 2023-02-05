#include <stdio.h>

/*
 a = 10;

 &a Denotes Pointer of 'a'
 *a Denotes Value at Pointer 'a'

 */

char* foo(char* str)
{
    char* first = &str[0];

    return first;

}

int main()
{
    printf("Hello World\n");

    char str[] = {'H','e','l','l','o',' ','R','a','J'};

    char* p = foo(str);

    *p = 'A';

    printf("Val : %s\n",str);

}
