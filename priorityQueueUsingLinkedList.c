#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char* str;
    int priority;
    struct Node* next;
}Node;


typedef struct Queue{

    Node* front;
    Node* rear;

}Queue;

Node* createNode(char *str,int priority){

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Management Failed !! \n");
        return NULL;
    }
    newNode->str = (char*)malloc(sizeof(char)*strlen(str)+1);
    strcpy(newNode->str,str);
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory Management Failed !! \n");
        return NULL;
    }

    q->front = NULL;
    q->rear = q->front;
    return q;
}

void print(Node* start){
    Node* temp = start;
    while(temp != NULL){
        printf("%s -> %d\n",temp->str,temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

Node* enqueue(Queue* q,char* str,int priority){

    if(q->front == NULL){
        q->front = createNode(str,priority);
        q->rear = q->front;
        return q->front;
    }
    
    Node* prev = NULL;
    Node* temp = q->front;
    while(temp && temp->priority < priority){
        prev = temp;
        temp = temp->next;
    }
    Node* newNode = createNode(str,priority);
    if(prev == NULL){
        newNode->next = temp;
        q->front = newNode;
        return q->front;
    }
    if(temp == NULL){
        prev->next = newNode;
        q->rear = newNode;
        return q->front;
    }
    prev->next = newNode;
    newNode->next = temp;
    return q->front;

}

char* dequeue(Queue* q){

    if(q->front == NULL){
        return "NULL";
    }

    Node* temp = q->front;
    q->front = temp->next;
    temp->next = NULL;
    char* res = temp->str;
    free(temp);
    return res;
}


int main(){

    Queue* q = createQueue();
    q->front = enqueue(q,"MsDhoni",2);
    // printf("Debug");
    q->front = enqueue(q,"Raina",1);
    // print(q->front);
    q->front = enqueue(q,"Rohit",10);
    q->front = enqueue(q,"Virat",6);
    print(q->front);
    
    printf("Dequeue > %s\n",dequeue(q));
    print(q->front);





}