#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printArr(int arr[], int arrSize)
{

    for (int i = 0; i < arrSize; i++)
    {

        printf("%d ", arr[i]);
    }

    printf("\n");
}

typedef struct Stack
{

    int *arr;
    int top;
    int size;

} Stack;

Stack *createStack(int Size)
{

    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
    {
        return NULL;
    }

    s->arr = (int *)malloc(sizeof(int) * Size);
    s->top = -1;
    s->size = Size;

    return s;
}


Stack *push(Stack *s, int ch)
{

    // printf()

    if (s->size == s->top - 1)
    {

        printf("OverFlow!!");
        return s;
    }

    s->arr[++s->top] = ch;

    return s;
}

int pop(Stack *s)
{

    if (s->top == -1)
    {
        printf("UnderFlow");
        return '0';
    }

    int temp = s->arr[s->top--];
    return temp;
}


int peek(Stack *s)
{
    
    return s->arr[s->top];
}

bool isEmpty(Stack* s){

    if(s->top == -1){
        return true;
    }

    return false;

}


void printStack(Stack* s){

        if(s->top == -1){
            return;
        }
        int x = peek(s);
        pop(s);
        printf("|_%d_|\n",x);
        printStack(s);

        s= push(s,x);

}

void stockSpan(int arr[], int arrSize)
{

    Stack *s1 = createStack(arrSize + 1);
    Stack *s2 = createStack(arrSize + 1);

    int res[arrSize];
    // s1 = push(s1, -1);
    // s2 = push(s2, -1);

    for (int i = 0; i < arrSize; i++)
    {

        int count = 1;
        if (isEmpty(s1) ||  peek(s1) > arr[i])
        {

            // printf(" running for :-- %d \n", arr[i]);
            push(s1, arr[i]);
            res[i] = count;
        }
        else
        {   
            // printStack(s1);
            // printf("\n");

            while ( !isEmpty(s1) && peek(s1) <= arr[i])
            {
                // printf("before pop %d -> ", peek(s1));
                s2 = push(s2, pop(s1));
                // printf("after pop %d\n", peek(s1));
                // printf("%d in while:-- %d %d\n", count, peek(s1), arr[i]);
                count++;
            }

            res[i] = count;
            // printf("after while loop %d -> %d\n", arr[i], res[i]);
            while (!isEmpty(s2))
            {
                s1 = push(s1, pop(s2));
            }

            s1 = push(s1,arr[i]);
        }
    }

    printArr(res, arrSize);
}

int main()
{

    int arr[100];
    int arrSize = 0;
    while (1)
    {

        int num = 0;
        scanf("%d", &num);
        arr[arrSize++] = num;

        char ch = getchar();
        if (ch == EOF || ch == '\n')
        {

            break;
        }
    }

    stockSpan(arr, arrSize);

    printArr(arr, arrSize);
}