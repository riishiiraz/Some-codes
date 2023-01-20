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

void input(char *ch , char *prompt){
    printf("%s",prompt);
    scanf("%s",ch);
}

void print(char *ch){
    printf("%s\n",ch);
}

