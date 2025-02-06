#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum Priority
{

    GENERAL = 1,
    SENIOR_CITIZEN,
    VIP

} Pr;

typedef struct Node
{
    int id;
    enum Priority pr;
    char *name;
    struct Node *next;
    
} Node;

Node *createNode(int id, enum Priority pr, char *name)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->pr = pr;
    newNode->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

int print(Node* head){

    Node* temp = head;
    int count = 0;
    while(temp != NULL){
    // printf("error in print");
        printf("%d - %s type :- %d\n",temp->id,temp->name,temp->pr);
        count++;
        temp = temp->next;
    }
    printf("\n");
    return count;
}


Node *push(Node *head, int id, Pr pr, char *name)
{

    if (head == NULL)
    {
        return createNode(id, pr, name);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newNode = createNode(id,pr,name);
    temp->next = newNode;
        // print(head);
    return head;
}

Node* pop(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    print(temp);
    free(temp);
    return head;
}

int main(){
    Node* head = createNode(1,1,"Utkarsh");
    // printf("hello world");
    head = push(head,102,2,"Sumit");
    head = push(head,103,3,"Jainam");
    head = push(head,104,1,"Hari");
    head = push(head,107,2,"Nothing");
    print(head);
    head = pop(head);
    print(head);


}