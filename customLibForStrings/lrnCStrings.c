#include <stdio.h>

int len(char *str)
{
    int i=0;
    for (i ; str[i]!=0 ; i++)
    {}
    return i;
}

char *cat(char *s1 ,char *s2)
{
    int l1 = len(s1);
    int i=0;
    char ch = s2[i];
    while (ch!=0)
    {
        s1[l1+i] = s2[i];
        ch = s1[i];
        i ++;
    }

    return s1;
}

void copy(char *s1 , char *s2)
{
    int i=0;
    char ch = s1[i];

    while (ch!=0)
    {
        s2[i] = s1[i];
        i++;
        ch = s1[i];
    }
}

int find(char *str , char ch)
{
    for (int i=0 ; str[i]!=0 ; i++)
        if(str[i]==ch) return i;

    return -1;
}

int count(char *str , char ch)
{
    int c=0;
    for (int i=0 ; str[i]!=0 ; i++)
        if(str[i]==ch) c++;
    return c;
}

int main()
{
    printf("Hello World\n\n");


    char str1[50] = "This is a string ! ";
    char str2[] = "This is a Second string !";

    char nul[100];

    scanf("%s",&nul);


    //

    // printf("Len = %d",len("str2"));

    // printf("\nS1 : %s",str1);
    // printf("\nS2 : %s",str2);

    //copy(cat(str1 , str2) , nul);

    printf("%d",count(nul , 'a'));






}

