#include <stdio.h>

/*
 a = 10;

 &a Denotes Pointer of 'a'
 *a Denotes Value at Pointer 'a'

 */

void encrypt(char *str , int key){
    for (int i=0;str[i]!='\0';i++)
        str[i]+=key;
}

void decrypt(char* str , int key){
    for (int i=0 ; str[i]!='\0' ; i++)
        str[i]-=key;
}

int main()
{
    char str[] = "Hello World";
    int ch=0;

    while (ch!=3)
    {
        printf("\nEnter \n");
        printf("1] for Encrypt \n");
        printf("2] for Decrypt \n");
        printf("3] for Exit \n");
        scanf("%d",&ch);

        if(ch==1){
            char x[10];
            int key=5;

            printf("\nEnter Text To Encrypt : ");
            scanf("%s",&x);

            printf("\nEnter key For Encryption : ");
            scanf("&d",&key);

            encrypt(x,key);


            printf("\nEncrypted Text : %s\n",x);

            printf("\nExit/Continue ? ");
            scanf("%d",&ch);


        }

        else if(ch==2){
            char x[10];
            int key=5;

            printf("\nEnter Encrypted To Decrypt : ");
            scanf("%s",&x);

            printf("\nEnter key For Decryption : ");
            scanf("&d",&key);

            decrypt(x,key);


            printf("\nDecrypted Text : %s\n",x);

            printf("\nExit/Continue ? ");
            scanf("%d",&ch);
        }



    }
    printf("String : %s",str);

}

