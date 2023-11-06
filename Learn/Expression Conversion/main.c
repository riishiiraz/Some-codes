//Code still in progress ! [Might not work at the moment]

#include<stdio.h>
#include<stdlib.h>

int strlen(char *str){
    int len=0;

    for (;str[len];len++);

    return len;
}

struct stack{
    char *ptr;
    int size;
    int top;
};

int isEmpty(struct stack *s){
    return s->top<0;
}

char peek(struct stack *stk){
    if(!isEmpty(stk)){
        return stk->ptr[stk->top];
    }
}

void display(struct stack *stk){
    for (int i=0;i<=stk->top;i++){
        printf("%c, ",stk->ptr[i]);
    }
}

void push(struct stack *stk , char item){
    if( (stk->top+1) < (stk->size) ){
        stk->ptr [++(stk->top)] = item;
    }

}

char pop(struct stack *stk){
    if(!isEmpty(stk)){
        return stk->ptr[(stk->top)--];

    }
}

int precedence(char ch){
    if(ch=='*' || ch=='/')  return 3;
    else if(ch=='+' || ch=='-')  return 2;
    else return 0;
}

int isOperator(char ch){
    if(ch=='*' || ch=='-' || ch=='/' || ch=='+' )
    return 1;
    return 0;
}

char *postfix(char *infix){

    struct stack *stk;
    stk->size=20;
    stk->top=-1;
    stk->ptr = (char*) malloc((stk->size)*(sizeof(char)));


    char *out = (char*)malloc((strlen(infix)+1) *sizeof(char) );

    int i=0,j=0;

    while (infix[i]!=0){
        if(!isOperator(infix[i])){
            out[j]=infix[i];
            j++;
        }


        else {
        
        if(precedence(infix[i])  > precedence(peek(stk)) )
            push(stk,infix[i]);

        else{
            while (!isEmpty(stk))
            {
                out[j++] = pop(stk);

                if(precedence(infix[i]) > precedence(peek(stk)))
                    continue;

            }
            push(stk,infix[i]);
            

        }

        }




        //printf("\n%d\n",stk->top);
        //display(stk);
        



        i++;
    }

    while (!isEmpty(stk)){
        printf("\nss %c",pop(stk));
        //out[j++]=pop(stk);
    }

    out[j++]=0;
    display(stk);
    return out;
}


void main(){
    

    char *infix = "X-Y/Z-K*D";

    printf("\nPostfix : %s",postfix(infix));



}

