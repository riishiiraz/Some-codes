#include <iostream>
#include <stdlib.h>

using namespace std;

template <class TYPE> class Stack{


    int size,top=-1;

    TYPE *data;

    void initStack(){
        this-> data =(TYPE*) malloc(sizeof(TYPE)*this->size);
    }

    public:

    Stack(){}
    
    Stack(int size){
        this->size = size;
        initStack();
    }


    void show(){
        cout<<"Showing the Stack : "<<endl;
        for (int i=0;i<=top ; i++){
            cout<<data[i]<<", ";
        }
        cout<<"\nTOP : "<<top<<endl;
    }


    void push(TYPE data){
        if((top+1)<size){
            this->data[++top] = data;
        }
        else cout<<"OverFlow !!"<<endl;
    }

    bool isEmpty(){
        return top<0;
    }

    TYPE pop(){
        if(!isEmpty()){
            return data[top--];
        }
    }

    TYPE peek(){
        if(!isEmpty()){
            return data[top];
        }
    }
};

class Expression{

    Stack <char> stack;

    
    void initStack(int size=20){
        stack = Stack<char> (size);
    }

    bool isOperator(char ch){
        if (ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
            return true;
        return false;
    }

    int strlen(char *str){
        int len=0;
        for (;str[len];len++);
        return len;
    }

    int precedence(char opr){
        if(opr=='^')    return 3;
        else if(opr=='*' || opr=='/')    return 2;
        else if(opr=='+' || opr=='-')    return 1;
        
        else return 0;
    }

    public:

    Expression(){
        //initStack();
    }
    
    char *infixtoPostfix(char *infix){
        initStack();
        char *postfix = (char*) malloc(sizeof(char)* (strlen(infix)+1) );

        char ch;
        int j=0;

        for (int i=0 ; ch=infix[i] ; i++){



            if(!isOperator(ch)){ // For Operands
                postfix[j++] = ch;
            }

            else{  // For Operators

                if(precedence(ch) > precedence(stack.peek())){
                    stack.push(ch);
                }

                else{
                    while (! stack.isEmpty() ){
                        postfix[j++] = stack.pop();

                        if(precedence(ch) > precedence(stack.peek()))
                            continue;
                    }
                    stack.push(ch);
                }

            }



        }

        while (!stack.isEmpty())
        {
            postfix[j++] = stack.pop();
        }
        


        postfix[j++]='\0';
        return postfix;
    }

};


int main(){
    
    char infix[] = "X-Y/Z-K*D";
    char *postfix;

    Expression expression = Expression();

    postfix = expression.infixtoPostfix(infix);

    cout<<"\nPostFix : "<<postfix<<endl;

}