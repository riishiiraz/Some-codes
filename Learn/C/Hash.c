#include <stdio.h>
#include <stdlib.h>

#define log(x) printf("\nlog : %d",x)

#define HASH_TABLE_SIZE 10

char* HASHES[HASH_TABLE_SIZE] = {NULL};

int getKey(char *str){
    int sum=0;
    for(int i=0; str[i] ; i++){
        sum+= str[i];
        if(i==0)  continue;
        sum += abs(str[i]-str[i-1]);
    }
    // for ( ; *str ; sum+=(*str), str++ ) ;
    return sum;
}

int getOffset(int key){
    return key % HASH_TABLE_SIZE;
}

void addString(char *str){
    *( HASHES + getOffset(getKey(str)) ) = str;
}

char* getString(char* str){
    return *( HASHES + getOffset(getKey(str)) ) ;
}

void printHashTable(){
    for (int i=0 ; i<HASH_TABLE_SIZE ; i++){
        if(HASHES[i]) printf("\n%d : %s",i,HASHES[i]);

        else printf("\n%d : <-->",i);
    }
}




void main(){

    char *str = "HelloWorld";
    char *str2 = "Hello Raj";

    addString(str);
    addString("Raj");
    addString("Rishi");
    addString("Rishi1");
    addString("Rishi2");

    log(getOffset(getKey(str)));
    log(getOffset(getKey(str2)));


    printf("\nStored String : %s",getString(str));


    printHashTable();








    printf("\n\nExit Sucesfully !\n");


}