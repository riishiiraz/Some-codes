#include <iostream>

#define print(str) cout << str << endl

#define cout std::cout
#define endl std::endl


class A{

    public :

    void funA(){
        cout<<"I am in Class A"<<endl;
    }

};

class B:virtual public A{

    // members of A is Inherited Here

    public :

    void funB(){
        cout<<"I am in Class B"<<endl;
    }

};

class C:virtual public A{
    // members of A is Inherited Here Also
    public :

    void funC(){
        cout<<"I am in Class C"<<endl;
    }

};

class D: public B, public C{
    // members of B and C are Inherited Here
    // Note: B and C both Already Inherits "A"
    // So D Should have members of "A" 2 times [from B & C].
    // To Avoid this Ambiguity, We Use "Virtual" class technique, when Inheriting the MASTER class.
    public:

    void funD(){
        cout<<"I am in Class D"<<endl;
    }
};


int main(){

    D d;
    d.funA();
    // THIS WILL INVOKE THE 'A' CLASS'S METHOD SMOTHLY BECAUSE 'A' IS INHERITED ONLY ONCE. 
    // [BECAUSE WE USED 'VIRTUAL' CLASS TECHNIQUE].
        
} 