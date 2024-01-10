#include <iostream>

#define print(str) cout<<str<<endl

#define cout std::cout
#define endl std::endl

class A{
    int age;
    char* name;

    public:

    A():age(45), name("Default"){
    }

    void disp(){
        cout<<"Name : "<<name<<" & Age :"<<age<<endl;
    }

    friend void setData(A& ,int,char*);
    // WE ARE PASSING THE REFERENCE OF THE OBJECT SO THAT WE CAN DEAL WITH THE PASSED OBJECT [NOT THE COPIED FUNCTION ARGUEMENT] 
};

void setData(A& a, int age, char* name){
    a.age = age;
    a.name = name;
}


int main(){

    print("\n");

    char name[] = "Rishi";
    int age = 420;
    

    A a;

    setData(a, age, name);
    a.disp();

    print("\n\nExit Succesfully !!");

    
}