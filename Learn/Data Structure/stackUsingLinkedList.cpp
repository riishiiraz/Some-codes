#include <iostream>

#define MODE_DEBUG 999
#define MODE_RELEASE 998

#define MODE MODE_DEBUG

#if MODE == MODE_DEBUG
#define LOG(x,y) std::cout<<"Log ( "<<x<<" : "<<y<<" )\n" 
#elif MODE == MODE_RELEASE
#define LOG(x,y) 
#endif

template <typename type> class linkedList{
    struct Node
    {
        type data;
        Node* next;
    };

    Node* getNode(){
        return (Node*)malloc(sizeof(Node));
    }

    Node* head = nullptr;

    public:

    void addFront(type ele){
        if(head==nullptr){
            head = getNode();
            head->data = ele;
            head->next = nullptr;
        }
        else{
            Node* newNode = getNode();
            newNode->data = ele;
            newNode->next = head;
            head = newNode;
        }
    }

    void addLast(type ele){
        Node *tepmHead = head;
        while(tepmHead->next){
            tepmHead = tepmHead->next;
        }

        Node* newNode = getNode();
        newNode->data = ele;

        tepmHead->next = newNode;
        newNode->next = nullptr;
    }

    type deleteLast(){
        if(head == nullptr){
            std::cout<<"UnderFlow !\n";
            return -999;
        }
        if(head->next == nullptr){
            type dat = head->data;
            head = nullptr;
            return dat;
        }

        Node *tempHead = head;
        Node *prev = head;
        while(tempHead->next){
            prev = tempHead;
            tempHead = tempHead->next;
        }
        prev->next = nullptr;
        return tempHead->data;
    }

    void disp(){
        Node *tempHead = head;
        std::cout<<"Printing List : [ ";
        while(tempHead){
            std::cout<<tempHead->data<<", ";
            tempHead = tempHead->next;
        }
        std::cout<<"]\n";
    }
};

template <typename type> 
class Stack{

    class Node{
        public:
        type data;
        Node* prev;
        Node () = default;
        Node(type dat):data(dat),prev(nullptr){}
    };

    Node *top;

    
    public:
    Stack(){top = nullptr;}

    void push(type dat){
        if(top==nullptr){
            top = new Node(dat);
        }
        else{
            Node* newNode = new Node(dat);
            newNode->prev = top;
            top = newNode;
        }        
    } 

    type pop(){
        if(top==nullptr){
            std::cout<<"\nUnderflow !!\n";
            return -999;
        }
        type temp = top->data;
        top = top->prev;
        return temp;
    }

    type peek(){
        if(top==nullptr){
            std::cout<<"\nUnderflow !!\n";
            return -999;
        }

        return top->data;
    }

    void disp(){
        std::cout<<"Printing The Stack [ ";
        Node *tempHead = top;

        while(tempHead){
            std::cout<<tempHead->data<<" -> ";
            tempHead = tempHead->prev;
        }

        std::cout<<"]\n";
    }



};

int main(){

    #if 0

    LOG("Holl",345);

    linkedList<int> list;
    list.deleteLast();

    list.addFront(5);
    list.addFront(6);
    list.addFront(7);

    list.addLast(69);
    list.addLast(420);
    list.addFront(707);

    list.disp();

    list.deleteLast();
    list.deleteLast();
    list.deleteLast();

    list.disp();

    #endif

    Stack<int> stack;

    stack.push(5);
    stack.push(55);
    stack.push(56);

    stack.disp();


    LOG("popped",stack.pop());
    LOG("popped",stack.pop());
    LOG("popped",stack.pop());
    LOG("popped",stack.pop());
    stack.disp();
    
    std::cout<<"\n\nExit Succesfully\n\n";
}
