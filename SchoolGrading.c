#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum Grades{

    A = 1,
    B,
    C,
    D,
    E
}grade;

typedef struct Node{

    char* name;
    grade g;
    struct Node* next;
}Node;


Node* createNode(char* name , grade g){

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->name = (char *)malloc(sizeof(char)*strlen(name)+1);
    strcpy(newNode->name,name);
    newNode->next = NULL;
    newNode->g = g;
    return newNode;

}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        printf("%s -> %d\n",temp->name,temp->g);
        temp = temp->next;
    }
    printf("\n");

}


grade returnGradeValue(char c){

    if(c == 'A'){
        return A;
    }
    else if(c == 'B'){
        return B;
    }
    else if(c == 'C'){
        return C;
    }
    else if(c == 'D'){
        return D;
    }
    else if(c == 'E'){
        return E;
    }
    else {

        return E;
    }


}

Node* insert(Node* head,char* name,grade g){

    if(head == NULL){
        return createNode(name,g);
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = createNode(name,g);
    temp->next = newNode;
    return head;

}

Node* getMiddle(Node* head){
if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head -> next;

    while(fast && fast->next){

        fast = fast->next->next;
        if(fast)
        slow = slow->next;

    }

    return slow;
}


Node* mergeSort(Node* left,Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* dummy = createNode("Nothing",returnGradeValue('A'));
    Node* temp = dummy;

    while(left != NULL && right != NULL){

        if(left->g > right->g){
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
        else{

            temp->next = left;
            temp = temp->next;
            left = left->next;
        }


    }

    while(left != NULL){
         temp->next = left;
            temp = temp->next;
            left = left->next;
    }

    while(right != NULL){
        temp->next = right;
            temp = temp->next;
            right = right->next;
    }

    return dummy->next;
    // if(left->g <= right->g)
    // {
    //     left->next = mergeSort(left->next,right);
    //     return left;
    // }

//    right->next = mergeSort(left,right->next);
//         return right;
}

Node* merge(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* middle = getMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;

    left = merge(left);
    right = merge(right);

    Node* res = mergeSort(left,right);
    return res;
}

int main(){

    Node* head = NULL;

    int noOfStudents = 0;
    scanf("%d",&noOfStudents);

    while(noOfStudents--){

        char str[100];
        printf("Enter Name and Grade :-- ");
        scanf("%s",str);
        getchar();
        char grade = 0;
        scanf("%c",&grade);
        head = insert(head,str,returnGradeValue(grade));

    }
    print(head);
    head = merge(head);
    print(head);

}