#include <iostream>

#define MODE_DEBUG 999
#define MODE_RELEASE 998

#define MODE MODE_RELEASE

#if MODE == MODE_DEBUG
#define LOG(x,y) std::cout<<"Log ( "<<x<<" : "<<y<<" )\n" 
#elif MODE == MODE_RELEASE
#define LOG(x,y) 
#endif 

struct Node
{
    int data;
    Node *left, *right;

    Node() :left(nullptr), right(nullptr) {}
    Node (int data): data(data),left(nullptr), right(nullptr) {}    
};

class binaryTree{

    Node *root;

    Node* getNode(){
        Node* newNode = new Node;
        return newNode;
    }
    Node* getNode(int data){
        Node* newNode = new Node(data);
        return newNode;
    }

    void preOrder_(Node* tempNode){
        // root -> left -> right
        
        if(tempNode!=nullptr){
            std::cout<<tempNode->data <<" ";
            preOrder_(tempNode->left);
            preOrder_(tempNode->right);
        }

    }
    void postOrder_(Node* tempNode){
        // left -> right -> root

        if(tempNode!=nullptr){
            preOrder_(tempNode->left);
            preOrder_(tempNode->right);
            std::cout<<tempNode->data <<" ";
        }

    }

    void inOrder_(Node* tempNode){
        // left -> right -> root

        if(tempNode!=nullptr){
            preOrder_(tempNode->left);
            std::cout<<tempNode->data <<" ";
            preOrder_(tempNode->right);
        }

    }
    

    public:
    binaryTree(){
        root = nullptr;
    };

    void preOrder(){
        std::cout<<"Pre-Order : ";
        preOrder_(root);
        std::cout<<"\n";
    }
    void postOrder(){
        std::cout<<"Post-Order : ";
        postOrder_(root);
        std::cout<<"\n";
    }
    void inOrder(){
        std::cout<<"In-Order : ";
        inOrder_(root);
        std::cout<<"\n";
    }

    void addElement(int data){
        if(root==nullptr){
            root = getNode(data);
            return;
        }

        Node* tempRoot = root;
        Node* onWhichNodeToInsert = root;

        bool direction;

        while(tempRoot){

            onWhichNodeToInsert = tempRoot;
            if( data < tempRoot->data ){
                
                tempRoot = tempRoot->left;
                direction = 0;
            }
            else{
                tempRoot = tempRoot->right;
                direction = 1;
            }
        }


        if(direction)   {onWhichNodeToInsert->right =  new Node(data);LOG("RIGHT",data);}
        else            {onWhichNodeToInsert->left = new Node(data);LOG("LEFT",data); }
    }




};

int main(){

    binaryTree tree;

    #if 1
    tree.addElement(5);
    tree.addElement(1);
    tree.addElement(2);
    tree.addElement(3);
    tree.addElement(4);
    #endif
    
    tree.preOrder();
    tree.postOrder();
    tree.inOrder();
    

    std::cout<<"\n\nExit Succesfully\n\n";
}
