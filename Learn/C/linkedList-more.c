#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

void addNode(int data, Node **head)
{

    if (*head == NULL)
    {
        Node *new = malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;
        *head = new;
    }
    else
    {

        Node *new = malloc(sizeof(Node));

        new->data = data;
        new->next = *head;
        *head = new;
    }
}

void disp(Node *head)
{
    printf("\nShowig The Linked List :\n");

    Node *temp = head;

    while (temp)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

void addLast(int data, Node* head){


    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    while(head->next){
        head=head->next;
    }

    head->next = new;
}

int pop(Node *head){
    Node *prev = head;

    while(head->next){
        prev = head;
        head = head->next;
    }

    prev->next = NULL;
    int toReturn = head->data;
    free(head);

    return toReturn;
}

void main(){
    Node* head = NULL;

    addNode(34,&head);

    disp(head);

    addNode(36,&head);
    
    disp(head);


    addLast(55, head);
    addLast(65, head);
    disp(head);

    int popped = pop(head);

    printf("\n\nPopped Element : %d",popped);

    disp(head);

    printf("\n\nExit Succesfully !!\n");
}