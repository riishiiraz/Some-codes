#include <iostream>
using namespace std;

class Calculate{

    public: int A,B;

    Calculate(int a,int b){
        A = a;
        B = b;
    }

    int add(){return A+B;}
    int mul(){return A*B;}

};

class Scientific:private Calculate{

    public :int A,B,C;

    Scientific(int a,int b,int c){
        A=a;
        B=b;
        C=c;
    }
    int sqr(){return 3*3;}

};


int main(){
    int a,b,r=0;
    a=5;b=6;

    Calculate calc = Calculate(a,b);
    cout<<calc.mul()<<endl;

    Scientific scin = Scientific(a,b,8);
    cout<<scin.sqr()<<endl;
}
