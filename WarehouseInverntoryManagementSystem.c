#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
        int quantity;
        char* items;
        struct Node* next;
}Node;


Node* createNode(int quantity,char* items){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->items = (char*) malloc((sizeof(char)*strlen(items))+1);
    strcpy(newNode->items,items);
    newNode->quantity = quantity;
    newNode->next = NULL;
    return newNode;

}


int list(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%s -> %d\n",temp->items,temp->quantity);
        temp = temp->next;
    }
    printf("\n");
}

Node* add(Node* head, int quantity, char* items) {
    Node* newNode = createNode(quantity, items);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->items, items) == 0) {
            temp->quantity += quantity;
            return head;
        }
        if (temp->next == NULL) {
            break;
        }
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}


Node* update(Node* head,int quantity,char* items){

    if(head == NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp->next != NULL){

        if(strcmp(temp->items,items)== 0){
            temp->quantity = quantity;
            return head;
        }
        temp = temp->next;
    }

    return head;

}

int Query(Node* head,char* item){

    if(head == NULL){
        return -1;
    }

    Node* temp = head;
    while(temp != NULL){

        if(strcmp(temp->items,item)== 0){
            return temp->quantity;
        }
        temp = temp->next;
    }

    return -1;
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
        printf("1. Add\n"); 
        printf("2. Update\n"); 
        printf("3. List\n"); 
        printf("4. Default Exit....\n"); 
        scanf("%d",&choice);

        switch(choice){

            case 1:{
                printf("Enter Item Name > ");
                scanf("%s",str);
                printf("Enter quantity > ");
                scanf("%d",&val);
                head = add(head,val,str);
                break;
            }
            case 2:{
                printf("Enter Item Name > ");
                scanf("%s",str);
                printf("Enter quantity > ");
                scanf("%d",&val);
                head = update(head,val,str);
                break;
            }

            case 3:{
                list(head);
                break;
            }

            default: return 0;

        }

    }
    return 0;

}