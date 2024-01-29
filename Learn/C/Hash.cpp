#include <iostream>
#include <stdlib.h>

#define log(x,y) std::cout << "\nlog | "<<x<<" : "<<y<<"\n"

template <class T_KEY,class T_VALUE, int HASH_TABLE_SIZE>
class Hash{

    T_VALUE* HASH_TABLE[HASH_TABLE_SIZE] = {nullptr};

    size_t getOffset(const char* str){
        size_t h=37;

        for (; *str ; h=(h*54059) ^ (*str * 76963) ,*str++);

        return h%86969 % HASH_TABLE_SIZE;
    }

    size_t getOffset(const T_KEY &data){
        return ((data*54059) ^ (data*76963)) % 86969 % HASH_TABLE_SIZE;
    }
    


public:

    // Hash() = default;

    bool addValue(T_KEY key, T_VALUE value){
        size_t offset = getOffset(key);
        // T_VALUE* ofsetPointer = (HASH_TABLE+getOffset(key));
        T_VALUE* ofsetPointer = (HASH_TABLE)[offset];
        
        if(ofsetPointer == nullptr){    

            HASH_TABLE[offset] = (T_VALUE*)malloc(sizeof(T_VALUE));
            *HASH_TABLE[offset] = value;

            // log("DEBUG ",value);
            return true;
        }
        return false;
    }

    T_VALUE* getValue(T_KEY key) {
        T_VALUE* ofsetPointer = (HASH_TABLE)[getOffset(key)];

        return ofsetPointer;
    }

    void printHashTable(){
        for (int i=0 ; i<HASH_TABLE_SIZE ; i++){
            if(HASH_TABLE[i]!=nullptr)  std::cout<<"\n "<<i<<" -> "<<*HASH_TABLE[i]<<"";
            else std::cout<<"\n "<<i<<" -> <--null-->";
        }
    }
};




int main()
{
    Hash<int, float, 10> hash;

    bool state1 = hash.addValue(91, 69.6969);
    bool state2 = hash.addValue(90, 487.6969);

    log("state1",state1);
    log("state2",state2);


    float* val1 = hash.getValue(91);
    float* val2 = hash.getValue(90);

    if(val1!=nullptr){
        log("val1",*val1);
    }
    else log("val1","NULL");



    if(val2!=nullptr){
        log("val2",*val2);
    }
    else log("val2","NULL");

    // hash.addData("Helo");

    // Hash hh('a');


    hash.printHashTable();


    std::cout<<"\nExit Succesfully !";
}



void test(){
    Hash<int, long, 50> hash;

    int choice=0,key;
    long val;
    long* v;


    while (choice != 4){

        std::cout<<"\n1 For Add";
        std::cout<<"\n2 For Get";
        std::cout<<"\n3 For Print Hash Table";
        std::cout<<"\n4 To EXIT";
        std::cout<<"\nEnter : ";


        std::cin>>choice;

        switch (choice){
            case 1:{
                std::cout<<"\nEnter Key And Value : ";
                std::cin>> key>>val;


                if(! hash.addValue(key, val)){
                    std::cout<<"\n KEY EXISTS ALREADY !";
                }
                else std::cout<<"\n DATA INSERTED !";
                break;
            }

            case 2:{
                std::cout<<"\nEnter Key : ";
                std::cin>>key;
                v = hash.getValue(key);
                if(v==nullptr) std::cout<<"\n NO VALUE FOUND !!";
                else std::cout<<"\n(KEY | VALUE ) [ "<<key<<" | "<<*v<<" ] ";
                break;
                
            }

            case 3: {hash.printHashTable();break;}



            case 4: break;
            
        }
    


    }
}

