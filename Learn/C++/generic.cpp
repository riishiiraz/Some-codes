#include <iostream>

using namespace std;

template <class T>
class generic
{
private:
    /* data */
    T val;
public:

    generic(T v){
        this->val=v;

    }




    void display(){
        cout<<"Value : "<<val<<endl;
        cout<<"Size  : "<<sizeof(val)<<endl;
    }
};


int main(){
    generic <float> g(5.0069);
    generic <float> g1 = generic<float>(50.09);

    g.display();
    g1.display();
}
