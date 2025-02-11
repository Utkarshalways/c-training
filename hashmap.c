#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define HASH_MULTIPLIER 8
 
int contactHash[100];
 
int computeHashCode(char userName[]) {
    int hash = 0;
    for (int i = 0; i < strlen(userName); i++) {
        hash = HASH_MULTIPLIER * hash + userName[i];
    }
    return hash % 100;
}
 
void add(char userName[], int userNumber) {
    int index = computeHashCode(userName);
    contactHash[index] = userNumber;
    printf("Success\n");
}
 
void search(char userName[]) {
    int index = computeHashCode(userName);
    if (contactHash[index] != 0) {
        printf("%d\n", contactHash[index]);
    } else {
        printf("Not Found\n");
    }
}
 
void delete(char userName[]) {
    int index = computeHashCode(userName);
    if (contactHash[index] != 0) {
        contactHash[index] = 0;
        printf("Success\n");
    } else {
        printf("Not Found\n");
    }
}
 
int main() {
    int num;
    scanf("%d", &num);
 
    for (int i = 0; i < num; i++) {
        char function[10], userName[100];
        int userNumber;
 
        scanf(" %[^(]", function);
 
        if (strcmp(function, "add") == 0) {
            scanf("(\"%[^\"]\", %d)", userName, &userNumber);
            add(userName, userNumber);
        } else if (strcmp(function, "search") == 0) {
            scanf("(\"%[^\"]\")", userName);
            search(userName);
        } else if (strcmp(function, "delete") == 0) {
            scanf("(\"%[^\"]\")", userName);
            delete(userName);
        }
    }
    return 0;
}
 