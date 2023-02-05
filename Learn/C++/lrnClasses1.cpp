#include <iostream>
using namespace std;

class bin{
    public :
        string b;
        int val=0;

    bin(string b){      // Constructor
        this->b = b;
    }


    private :
        int isBin();

    public :
        void show();
        int getVal();
        bin ones();     // method that returns self Type Object

};

void bin::show(){
    cout<<"0b"<<b<<endl;
}
int bin::isBin(){
    for (int i=0;i<b.length() ; i++){
        if( !(b.at(i)=='0' || b.at(i)=='1') )
            return 0;
    }
    return 1;
}

int bin:: getVal(){
    if(!isBin()) return -1;
    int j=1;
    val=0;
    for (int i=(b.length()-1); i>=0;i--){
        val+=(j*(b.at(i)=='1' ? 1:0));
        j=(j*2);
    }
    return val;
}

bin bin :: ones(){
        string b_=b;
        for (int i=0;i<b.length();i++){
            b_.at(i)=b.at(i)=='1'?'0':'1';
        }

        return bin(b_);
    }


int main(){
    cout<<"Program to Implement OOPs"<<endl<<endl;

    string s="10100010";
    bin x(s);
    //bin y = bin(s);   // Valid
    //bin z = s;        // Valid

    cout<<"Given Binary is : ";
    x.show();

    //cout<<"Value = "<<x.getVal()<<endl;
    //cout<<"Value = "<<bin("100101101").getVal()<<endl;

    cout<<"Original Value : "<<x.getVal()<<endl;
    cout<<"Ones Compliment Value : "<<x.ones().getVal()<<endl;


}
