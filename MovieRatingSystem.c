#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    char* movie;
    int rating;
    struct Node* next;
}Node;

Node* createNode(char* movie,int rating){

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->movie = (char*)malloc(sizeof(char)*strlen(movie)+1);
    strcpy(newNode->movie,movie);
    newNode->rating = rating;
    return newNode;
}

Node* list(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%s (%d) -> ",temp->movie,temp->rating);
        temp = temp->next;
    }
    printf("\n");
}

Node* add(Node* head,char* movie,int rating){
    Node* newNode = createNode(movie, rating);
    if(head == NULL) {
        return newNode;
    }

    if(head->rating < rating) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while(temp->next != NULL && temp->next->rating > rating) {
        if(strcmp(temp->movie, movie) == 0) {
            temp->rating = rating;
            return head;
        }
        temp = temp->next;
    }

    if(strcmp(temp->movie, movie) == 0) {
        temp->rating = rating;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}


char* top(Node* head){
    return  head->movie;
}

Node* removeNode(Node* head,char* movie){

    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    Node* prev = head;

    while(temp != NULL){
        if(strcmp(temp->movie,movie)==0){
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
    int val = 0;
    char* str = (char*)malloc(sizeof(char)*100);
    printf("Enter the No of Operations:-- ");
    int noOfOperations;
    scanf("%d",&noOfOperations);
    while(noOfOperations--){

        printf("Enter the Choice:-- \n");
        printf("1. Add\n"); 
        printf("2. Remove\n"); 
        printf("3. Top\n"); 
        printf("4. Default Exit....\n"); 
        scanf("%d",&choice);

        switch(choice){

            case 1:{
                printf("Enter Movie Name > ");
                scanf("%s",str);
                printf("Enter rating > ");
                scanf("%d",&val);   
                head = add(head,str,val);
                list(head);
                break;
            }
            case 2:{
                printf("Enter Movie Name > ");
                scanf("%s",str);
                head = removeNode(head,str);
                list(head);
                break;
            }
            
            case 3:{
                printf("%s\n",top(head));
                list(head);
                break;
            }

            default: break;

        }

    }
    return 0;


}