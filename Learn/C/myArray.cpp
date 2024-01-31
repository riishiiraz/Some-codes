#include <iostream>
#include <stdlib.h>
#include <string>

#define LOG(x,y) std::cout<<"Log ( "<<x<<" : "<<y<<" )\n"; 

template <class T>
class Array{

    size_t curSize=0;
    size_t curCapacity=2;
    T* array;

    bool extend(){
        // LOG("Realloc Called",curCapacity);
        curCapacity += (curCapacity/2);

        #if 0 //Enbale This to USE the other method of reallocating.
        T* Narray = (T*) malloc(sizeof(T)*curCapacity);
        for(int i=0;i<curSize;i++){
            Narray[i] = array[i];
        }
        free(array);
        array = Narray;

        #else
        
        array = (T*)realloc(array, curCapacity);

        #endif

        if(array == nullptr) return false;
        return true;
    }

    public:

    Array(){
        array = (T*)malloc(sizeof(T)*curCapacity);
    }

    bool append(T ele){
        if(curSize==curCapacity){
            if(!extend()) return false;
        }
        array[curSize++] = ele;
        return true;
    }

    void print(){
        std::cout<<"Array [ ";

        for (int i=0; i<curSize; i++){
            std::cout<<array[i]<<", ";
        }
        std::cout<<"]\n";

    }


    T& operator[](unsigned int ind){
        LOG("This is me ! ",45);

        try{
            if(curSize<=ind) throw ind;
            return array[ind];
        }
        catch(unsigned int ind){
            std::cout<<"Error !\n"<<"Index '"<<ind<<"' is out of Array !\n";
        }
        
    }

    size_t size(){return curSize;}
    size_t capacity(){return curCapacity;}
};



int main(){

    Array<int> arInt;
    Array<char> arChar;
    Array<std::string> arSting;
    

    arChar.append('a');
    arChar.append('b');
    arChar.print();
    
    arInt.append(1);
    arInt.append(2);
    arInt.append(3);
    LOG("Size",arInt.size());
    LOG("Capacity",arInt.capacity());
    LOG("SUBSCRIPT", arInt[2]);
    arInt[0]=420;
    arInt.print();


    arSting.append("Hello");
    arSting.append("Raj");
    arSting.print();
}