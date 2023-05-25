#include <stdio.h>
#include <stdlib.h>

void copyString(char str[], char *toCpy)
{
    int i = 0;
    for (i = 0; str[i] != 0; i++)
    {
        toCpy[i] = str[i];
    }
    toCpy[i] = 0;
}
int strLen(char *str)
{
    int i = 0;
    while (str[i] != 0)
        i++;
    return i;
}
int main()
{
    int totalStrings = 5;
    char **strings = malloc(sizeof(char *) * totalStrings);

    char buffer[10]; // Temporary String Buffer

    for (int i = 0; i < totalStrings; i++)
    {
        printf("Enter %dth string : ", i);
        scanf("%s", buffer);

        strings[i] = malloc(strLen(buffer) * sizeof(char));
        // *(strings+i) = malloc(strLen(buffer) * sizeof(char));
        
        copyString(buffer, *(strings + i));
        // copy(buffer , strings[i]);


        //*(strings+i) = "Hii";
    }
    printf("\n");

    for (int i = 0; i < totalStrings; i++)
    {
        printf("The %dth String is : %s\n", i, strings[i]);
    }

    free(strings);
}
