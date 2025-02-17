#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
        int roomNo;
        struct Node* next;
}Node;


Node* createNode(int room){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->roomNo = room;
    newNode->next = NULL;
    return newNode;

}


bool status(Node* head,int roomNo){
    Node* temp = head;
    while(temp != NULL){

        if(temp->roomNo == roomNo){
            return true;
        }
       
        temp = temp->next;
    }
    return false;
}

Node* turnOn(Node* head, int roomNo) {
    Node* newNode = createNode(roomNo);
    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head = newNode;
    return head;
}


Node* turnOff(Node* head, int roomNo) {
    
    if (head == NULL) {
        return head;
    }
    
    Node* temp = head;
    Node* prev = temp;
    while( temp != NULL){
        if(temp->roomNo == roomNo){
            prev->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}


int main(){

    Node* head = NULL;
    int choice;
    int val;
    char* str = (char*)malloc(sizeof(char)*100);
    printf("Enter the No of Operations:-- ");
    int noOfOperations;
    scanf("%d",&noOfOperations);
    while(noOfOperations--){

        printf("Enter the Choice:-- \n");
        printf("1. TurnOn\n"); 
        printf("2. TurnOff\n"); 
        printf("3. Status\n"); 
        printf("4. Default Exit....\n"); 
        scanf("%d",&choice);

        switch(choice){

            case 1:{
                printf("Enter Room No:-- > ");
                scanf("%d",&val);
                head = turnOn(head,val);
                break;
            }
            case 2:{
                printf("Enter Room No:-- > ");
                scanf("%d",&val);
                head = turnOff(head,val);
                break;
            }

            case 3:{
                printf("Enter Room No:-- > ");
                scanf("%d",&val);
                status(head,val)?printf("ON\n"):printf("OFF\n");
                break;
            }

            default: return 0;

        }

    }
    return 0;

}