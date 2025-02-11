#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum Complexities {
    ONE,
    LOG_N,
    SQRT_N,
    N,
    N_LOG_N,
    N_POW_K,
    TWO_POW_N,
    N_FACTORIAL
};

typedef struct Node {
    enum Complexities time;
    enum Complexities space;
    struct Node *next;
} Node;

enum Complexities getComplexities(char *str) {
    if (strcmp(str, "1") == 0) {
        return ONE;
    } else if (strcmp(str, "log_n") == 0) {
        return LOG_N;
    } else if (strcmp(str, "sqrt_n") == 0) {
        return SQRT_N;
    } else if (strcmp(str, "n") == 0) {
        return N;
    } else if (strcmp(str, "n_log_n") == 0) {
        return N_LOG_N;
    } else if (strcmp(str, "n_pow_k") == 0) {
        return N_POW_K;
    } else if (strcmp(str, "2_pow_n") == 0) {
        return TWO_POW_N;
    } else {
        return N_FACTORIAL;
    }
}

char *mappingTheComplexities(enum Complexities complexities) {
    switch (complexities) {
        case ONE: return "1";
        case LOG_N: return "log_n";
        case SQRT_N: return "sqrt_n";
        case N: return "n";
        case N_LOG_N: return "n_log_n";
        case N_POW_K: return "n_pow_k";
        case TWO_POW_N: return "2_pow_n";
        case N_FACTORIAL: return "n!";
    }
    return "NULL";
}

Node *createNode(enum Complexities time, enum Complexities space) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->time = time;
    newNode->space = space;
    newNode->next = NULL;
    return newNode;
}

Node *getMiddle(Node *head) {
    if (head == NULL) return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node* head) {
    Node* currNode = head;
    while(currNode != NULL){
        printf("%s %s\n",mappingTheComplexities(currNode->time),mappingTheComplexities(currNode->space));
        currNode = currNode->next;
    }
    printf("\n");
}

Node *mergeSort(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;

    Node *result = NULL;

    if (left->time < right->time || (left->time == right->time && left->space < right->space)) {
        result = left;
        result->next = mergeSort(left->next, right);
    } else {
        result = right;
        result->next = mergeSort(left, right->next);
    }

    return result;
}

Node* merge(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *middle = getMiddle(head);
    Node *right = middle->next;
    middle->next = NULL;

    Node *left = merge(head);
    right = merge(right);

    return mergeSort(left, right);
}

void sort(Node **head) {
    (*head) = merge((*head));
}

void insert(Node** head) {
    int n = 0;
    scanf("%d", &n);  
    while (n > 0) {
        char time[100];
        char space[100];
        scanf("%s %s", time, space);
        Node* newNode = createNode(getComplexities(time), getComplexities(space));
        newNode->next = (*head);
        (*head) = newNode;
        n--;
    }
}

int main() {
    Node* head = NULL;
    insert(&head);
    sort(&head);
    print(head);
    return 0;
}
