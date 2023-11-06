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
        //cout<<"Showing the Stack : ";
        for (int i=0;i<=top ; i++){
            // printf("%d ",data[i]);
            cout<<data[i]<<" ";
        }
        //cout<<endl;
        //cout<<"\nTOP : "<<top<<endl;
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
    Stack <int> stackInt;

    
    void initStack(int size = 20 ){
        stack = Stack<char> (size);
    }

    void initIntStack(int size = 20){
        stackInt = Stack<int> (size);
    }

    bool isOperator(char ch){
        if (ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-' || ch=='(' || ch ==')')
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

    void print(char *string_ , int length){
        for(int i=0;i<length;i++)
           cout<<string_[i];
    }

    void reverse(char *expr ,char *to, int len){
        int i=0;
        for ( ; len>=0 ; i++, len--){
            to[i]=expr[len-1];
        }
    }

    int performOperation(char operator_, int a ,int b){
        switch (operator_)
        {
        case '^': {int p=a;while (b--) p*=a;
            return p;
            }

        case '*': return a*b;
        case '/': return a/b;
        case '+': return a+b;
        case '-': return a-b;
        
        default:
            break;
        }
    }


    public:
    
    Expression(){}
    
    char *infixtoPostfix(char *infix , int showStack = 0){
        initStack();
        char *postfix = (char*) malloc(sizeof(char)* (strlen(infix)+1) );

        char ch;
        int j=0;

        for (int i=0 ; ch=infix[i] ; i++){


            if(!isOperator(ch)){ // For Operands
                postfix[j++] = ch;
            }

            else{  // For Operators

                if(ch=='('){
                    stack.push(ch);
                }

                else if(ch==')'){
                    char tmp=stack.pop();
                    while(tmp!='('){
                        postfix[j++]=tmp;
                        tmp=stack.pop();
                    }
                }

                else if(precedence(ch) > precedence(stack.peek())){
                    stack.push(ch);
                }

                else{
                    while (! stack.isEmpty() ){
                        postfix[j++] = stack.pop();

                        if(precedence(ch) > precedence(stack.peek()))
                            break;
                    }
                    stack.push(ch);
                }

            }

            if(showStack){
                cout<<ch<<"\t";
                stack.show();
                cout<<"\t\t";
                print(postfix,j);
                cout<<endl;
            }

            



        }

        while (!stack.isEmpty())
        {
            postfix[j++] = stack.pop();
        }
        


        postfix[j++]='\0';
        return postfix;
    }

    char *infixtoPrefix(char *infix , int showStack = 0){

        initStack();
        int length = strlen(infix);
        char *prefix = (char*) malloc(sizeof(char)* (length) );

        char *reverseInfix = (char*) malloc(sizeof(char)* (length) );
        reverse(infix, reverseInfix, length);


        char ch;
        int j=0;
        

        for (int i=0 ; i<length ; i++){

            ch=reverseInfix[i];


            if(!isOperator(ch)){ // For Operands
                infix[j++] = ch;
                
            }

            else{  // For Operators

                if(ch==')'){
                    stack.push(ch);
                }

                else if(ch=='('){
                    char tmp=stack.pop();
                    while(tmp!=')'){
                        infix[j++]=tmp;
                        tmp=stack.pop();
                    }
                }

                else if(precedence(ch) >= precedence(stack.peek())){
                    stack.push(ch);
                }

                else{
                    while (! stack.isEmpty() ){
                        infix[j++] = stack.pop();

                        if(precedence(ch) >= precedence(stack.peek()))
                            break;
                    }
                    stack.push(ch);
                }

            }

            
            if(showStack){
                cout<<ch<<"\t";
                stack.show();
                cout<<"\t\t";
                print(infix,j);
                cout<<endl;
            }

            



        }

        while (!stack.isEmpty())
        {
            infix[j++] = stack.pop();
        }
        

        char *output = (char*) malloc(sizeof(char) * (j+1));
        reverse(infix , output , j);
        output[j++] = '\0';

        free(infix);

        return output;

        

    }

    int solvePostfix(char* expression){
        
        initIntStack();

        char scan;
        int operand=0, wasDigit=0;

        for (int i=0 ; scan = expression[i] ; i++){

            if(isOperator(scan)){
                wasDigit=0;
                int a,b;
                b=stack.pop();
                a=stack.pop();
                stack.push(performOperation(scan , a,b));

            }

            else if (scan==' ' ){

                if (wasDigit) 
                    stack.push(operand);
                 
                 operand=0;
            }

            else{
                wasDigit=1;
                operand = (operand*10) + (scan-'0');   
            }
        }

        return stack.peek();

    }

    int solvePrefix(char* expression){
        /*
            This Method is ONLY reliable when operands are single digits.
            because (reversing the expression will also flip the digits)
            eg: [+ 12 5] will be changed to  [5 21 +] (12 became 21)
        */

        initIntStack();

        int len = strlen(expression);

        char* reversePrefix = (char*) malloc(sizeof(char) * len+1);
        reverse(expression , reversePrefix , len);
        reversePrefix[len] = '\0';


        char scan;
        int operand=0, wasDigit=0;

        for (int i=0 ; scan = reversePrefix[i] ; i++){

            if(isOperator(scan)){
                wasDigit=0;
                int a,b;
                b=stack.pop();
                a=stack.pop();
                stack.push(performOperation(scan , a,b));

            }

            else if (scan==' ' ){

                if (wasDigit) 
                    stack.push(operand);
                 
                 operand=0;
            }

            else{
                wasDigit=1;
                operand = (operand*10) + (scan-'0');   
            }

            
        }
        
        return stack.peek();

    }
};


int main(){
    
    //char infix[] = "X-Y/Z-K*D";
    char infix[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    char *postfix;
    char *prefix;

    Expression expression = Expression();

    postfix = expression.infixtoPostfix(infix, 1);
    cout<<"\nPostFix : "<<postfix<<endl;

    prefix = expression.infixtoPrefix(infix );
    cout<<"\nPreFix : "<<prefix<<endl;

    char postfixExp[] = "5 6 2 + * 12 4 / -";
    cout<<"\nSolved Postfix = "<<expression.solvePostfix(postfixExp)<<endl;

    char prefixExp[] = "+ 9 * 2 6";
    cout<<"\nSolved Prefix = "<<expression.solvePrefix(prefixExp)<<endl;
}
