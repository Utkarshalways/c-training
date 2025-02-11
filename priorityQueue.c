#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct PriorityQueue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->arr = (int*) malloc(capacity * sizeof(int));
    pq->front = -1;
    pq->rear = -1;
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

bool isFull(PriorityQueue* pq) {
    return pq->size == pq->capacity;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void enqueue(PriorityQueue* pq, int value) {
    if (isFull(pq)) {
        printf("PriorityQueue is full\n");
        return;
    }
    int i;
    for (i = pq->size - 1; (i >= 0 && pq->arr[i] > value); i--) {
        pq->arr[i + 1] = pq->arr[i];
    }
    pq->arr[i + 1] = value;
    
    if (pq->front == -1) {
        pq->front = 0;
    }
    pq->rear++;
    pq->size++;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PriorityQueue is empty\n");
        return -1;
    }

    int value = pq->arr[pq->front];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->rear--;
    pq->size--;

    if (pq->size == 0) {
        pq->front = -1;
        pq->rear = -1;
    }

    return value;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PriorityQueue is empty\n");
        return;
    }

    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue* pq = createPriorityQueue(5);

    enqueue(pq, 30);
    enqueue(pq, 20);
    enqueue(pq, 50);
    enqueue(pq, 10);
    enqueue(pq, 40);

    printf("PriorityQueue: ");
    display(pq);

    printf("Dequeue element: %d\n", dequeue(pq));
    printf("PriorityQueue after dequeue: ");
    display(pq);

    return 0;
}
