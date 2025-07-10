#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNewNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    return newNode;
}

void insert(int data)
{
    struct Node *newNode = createNewNode();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{

    if (head->next == NULL)
    {
        printf("%d",head->data);
        return;
    }

      struct Node* temp = head;

    while (temp->next != NULL)
    {
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("%d ->",temp->data);
}

void deleteAtLast(){
    struct Node* temp = head;
    struct Node* prev = head;
    temp = temp->next;
    while(temp->next != NULL){
       prev=prev->next;
       temp = temp->next;
    }
    prev->next = NULL;
}

void main()
{
    insert(20);
    insert(50);
    insert(30);
    display();
    deleteAtLast();
    printf("\n");
    display();
}