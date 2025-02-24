#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    char *val;
    struct Node *next;
    struct Node *prev;
} Node;

int printForward(Node *head)
{
    Node *print = head;

    while (print != NULL)
    {
        printf("%s -> ", print->val);
        print = print->next;

    }
    return 0;
  
}
Node *createNode(char* val)
{
    // printf("call");
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = (char *)malloc(sizeof(char) * strlen(val)+1);
    strcpy(newNode->val, val);
    newNode->prev = NULL;
    newNode->next = NULL;
    // printForward(newNode);
    return newNode;
}


Node *insertNode(Node *head, char *str)
{
    if (head == NULL)
    {
        Node* newNode = createNode(str);
        // printf("CAlled");
        head = newNode;
        // printForward(head);
        return head;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    Node *newNode = createNode(str);
    newNode->prev = temp;
    temp->next = newNode;
        // printForward(head);
    return head;
}

Node* previousSong(Node* head){

    if(head ->prev != NULL){
        return head->prev;
    }
    return head;

}

Node* nextSong(Node* head){

    if(head->next != NULL){
        return head->next;
    }
    return head;
}

int main()
{

    Node *playNode = NULL;
    playNode = insertNode(playNode, "La-Hasil");
    playNode = insertNode(playNode, "Bawae");
    playNode = insertNode(playNode, "Mockbird");
    playNode = insertNode(playNode, "LongTimeNoSee");

    printForward(playNode);

    while(1){

        int choice;

        printf("\n1. Next Song\n2.Previous Song\n");
        scanf("%d",&choice);
        

        switch(choice){

            case 1: playNode = nextSong(playNode);
                    printf("\n%s\n",playNode->val);
                    break;

            case 2: playNode = previousSong(playNode);
                    printf("\n%s\n",playNode->val);
                    break;

            default : return 1;       
        }

    }


}