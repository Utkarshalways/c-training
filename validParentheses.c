#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node{
    char data;
    struct Node* next;
};

    struct Node* head = NULL;

struct Node* createNode(char data){

    struct Node* newNode = (struct Node* ) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int getLength(struct Node* head){

    struct Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;  
    }

    return count;

}

bool isEmpty(struct Node* head){

    if(head == NULL){
        printf("Empty!! \n");
        return true;
    }
    return false;
}

struct Node* insertAtBeginning(struct Node* head,char data){

    if(head == NULL){

        head = createNode(data);
        return head;

    }

    struct Node* newNode = createNode(data);

    newNode->next = head;
    head = newNode;
    return head;

}


struct Node* push(struct Node* head,char data){

    return insertAtBeginning(head,data);


}

struct Node* pop(struct Node* head){

    if(head == NULL || head->next == NULL){
        head = NULL;
        return head;
    }

    struct Node* temp = head->next;
    head = temp;
    return head;

}

char peek(struct Node* head){

    if(isEmpty(head)){
        return -1;
    }

    // printf("%d\n",head->data);

    return head->data;

}
bool checkParentheses(char* str){


    for(int i = 0;i<strlen(str);i++){

        if(str[i] == '{' || str[i] == '(' || str[i] == '[' ){

            head = push(head,str[i]);

        } 

        else {


            if(head == NULL){

                return false;
            }
            else{

                if(str[i] == '}' && peek(head) == '{' || str[i] == ']' && peek(head) == '[' || str[i] == ')' && peek(head) == '('){

                    head = pop(head);

                }
                else{

                    return false;

                }
            }

        }

    }

    if(head != NULL){
        return false;
    }

    return true;

}


int main(){


    char val[100];
    printf("Enter the Parentheses :- ");
    scanf("%s",val);
    
    checkParentheses(val)?printf("True"):printf("False");


    return 0;
}
