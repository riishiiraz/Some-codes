#include <iostream>

#define print(str) cout << str << endl

#define cout std::cout
#define endl std::endl

// class B;
class A
{
    int age;
    char *name;

    void setData(int age, char *name) {
        age = age;
        name = name;
    }

    public:

    void disp() {
        cout << "Name : " << name << " & Age :" << age << endl;
    }

    friend class B;
    // WE ARE GIVING PERMISSIONS TO CLASS 'B' TO ACCESS THE PRIVATE MEMBERS OF THIS CLASS.
};

class B {

    public:

    void getInfo(A &a, int age, char *name) {
        a.age = age;
        a.name  = name;
        // ACCESSING THE PROIVTE MEMBERS OF CLASS 'A'.
    }
};

int main()
{
    A objA;
    B objB;

    int age = 420;
    char name[] = "Rishi";

    objB.getInfo(objA, age, name);
    objA.disp();
}