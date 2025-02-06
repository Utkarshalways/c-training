#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{

    int id;
    struct Node *next;
    bool isAvailable;

} Node;

Node *createNode(int id, bool isAvailable)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->isAvailable = isAvailable;
    newNode->next = NULL;
}

int print(Node *head)
{

    Node *temp = head;
    do
    {   
        printf("%d ( %d ) -> ",temp->id,temp->isAvailable);
        temp = temp->next;

    } while (temp != head);
        printf("%d ( %d )",head->id,head->isAvailable);
}

Node *InsertInLinkedList(Node *head, int id, bool isAvailable)
{

    if (head == NULL)
    {
        Node *newNode = createNode(id, isAvailable);
        newNode->next = newNode;
        head = newNode;
        return head;
    }

    Node *temp = head;
    do
    {
        temp = temp->next;

    } while (temp->next != head);

    Node *newNode = createNode(id, isAvailable);
    temp->next = newNode;
    newNode->next = head;
    return head;
}


int assignRides(Node* head){

    if(head == NULL){
        return -1;
    }

    Node* temp = head;

    do{

        if(temp->isAvailable){

            return temp->id;

        }
        temp = temp->next;


    }while(temp != head);


}


int main(){

    Node* head = NULL;

    head = InsertInLinkedList(head,101,true);
    head = InsertInLinkedList(head,102,false);
    head = InsertInLinkedList(head,103,true);
    head = InsertInLinkedList(head,104,false);
    head = InsertInLinkedList(head,105,true);
    head = InsertInLinkedList(head,106,false);

    print(head);


    printf("\n%d",assignRides(head));

}