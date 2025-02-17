#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{

    int page;
    struct Node* next;

}Node;


typedef struct Hashmap{
    int* arr;
    int totalCount;
    int size;
}Hashmap;


Hashmap* createHashmap(int size){   

    Hashmap* newMap = (Hashmap*)malloc(sizeof(Hashmap));
    newMap->arr = (int*)calloc(sizeof(int),size);
    newMap->totalCount = 0;
    newMap->size = size;
    return newMap;

}



Node* createNode(int page){

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Failed!!");
        return NULL;
    }
    newNode->page = page;
    newNode->next = NULL;
    return newNode;

}

bool isEmpty(Node* head){
    if(head == NULL){
        printf("No bookmarks\n");
        return true;
    }
    return false;
}

int printMap(Hashmap* map){

    for(int i = 0;i<map->size;i++){

        if(map->arr[i] > 0){
            printf("%d\n",i);
        }

    }
    printf("\n");

    return map->totalCount;
}


Node* push(Node* head,int page,Hashmap** map){

    Node* newNode = createNode(page);
    if(head == NULL){
        (*map)->arr[page]++;
        return newNode;
    }
    (*map)->arr[page]++;
    (*map)->totalCount++;
    newNode->next = head;
    head = newNode;
    return head;

}

int pop(Node** head,Hashmap** map){

    if(isEmpty(*head)){
        return -1;
    }

    int temp =(*head)->page;
    Node* t = (*head);
    (*head) = (*head)->next;
    free(t);
    (*map)->arr[temp]--;
    (*map)->totalCount--;
    return temp;

}

int main(){

    Node* head = NULL;
    Hashmap* map = createHashmap(1000);
    int choice;
    int page;
    printf("Enter the No of Operations:-- ");
    int noOfOperations;
    scanf("%d",&noOfOperations);
    while(noOfOperations--){

        printf("Enter the Choice:-- \n");
        printf("1. Bookmark\n"); 
        printf("2. Delete\n"); 
        printf("3. List\n"); 
        printf("4. Default Exit....\n"); 
        scanf("%d",&choice);

        switch(choice){

            case 1:{
                printf("Enter Page No > ");
                scanf("%d",&page);
                head = push(head,page,&map);
                break;
            }
            case 2:{
                pop(&head,&map);
                break;
            }

            case 3:{
                printMap(map);
                break;
            }

            default: return 0;

        }

    }
    return 0;
}