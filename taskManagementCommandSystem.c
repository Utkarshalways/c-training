#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
        char* task;
        bool isCompleted;
        struct Node* next;
}Node;


Node* createNode(char* task){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = (char*) malloc((sizeof(char)*strlen(task))+1);
    strcpy(newNode->task,task);
    newNode->isCompleted = false;
    newNode->next = NULL;
    return newNode;

}


int list(Node* head){
    Node* temp = head;
    int pending = 0;
    while(temp != NULL){
        if(!temp->isCompleted){
            printf("%s\n",temp->task);
            pending++;
        }
        temp = temp->next;
    }
    if(pending == 0){
        printf("There are no Task ");
    }
    printf("\n");
}

Node* add(Node* head, char* task) {
    Node* newNode = createNode(task);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}


Node* update(Node* head,char* task){

    if(head == NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp->next != NULL){

        if(strcmp(temp->task,task)== 0){
            temp->isCompleted = true;
            return head;
        }
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
        printf("1. Add\n"); 
        printf("2. Completed\n"); 
        printf("3. List\n"); 
        printf("4. Default Exit....\n"); 
        scanf("%d",&choice);

        switch(choice){

            case 1:{
                printf("Enter Task >");
                scanf("%s",str);
                head = add(head,str);
                break;
            }
            case 2:{
                printf("Enter Task >");
                scanf("%s",str);
                head = update(head,str);
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