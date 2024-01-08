
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    void *next;
};

typedef struct node Node;

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

int delete(int data, Node **head)
{

    Node *curr = *head;
    Node *prev = *head;

    int deleted;

    while (curr)
    {

        if (curr->data == data)
        {

            deleted = curr->data;

            prev->next = curr->next;

            return deleted;
        }

        prev = curr;

        curr = curr->next;
    }

    return -999;
}

void insert(int after, int data, Node **head)
{
    Node *cur = *head;

    Node *new = malloc(sizeof(Node));
    new->data = data;

    while (cur)
    {

        if (cur->data == after)
        {
            new->next = cur->next;
            cur->next = new;
            break;
        }

        cur = cur->next;
    }
}

void disp(Node *head)
{
    printf("Showig The Linked List :\n");

    Node *temp = head;

    while (temp)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    printf("\n\n");
    Node *head = NULL;

    // head = malloc(sizeof(Node));
    // head->data = 420;
    // head->next = NULL;

    addNode(34, &head);
    addNode(35, &head);
    addNode(36, &head);

    disp(head);

    int del = delete(35, &head);

    printf("\nDeleted Item : %d\n", del);

    disp(head);

    printf("\n\nAfter Insertion :\n");

    insert(36, 500, &head);

    disp(head);

    printf("\n\nExit Succesfully !!\n");
}