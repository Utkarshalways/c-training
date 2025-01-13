#include<stdio.h>
// Write a program in C to extract a substring from a given string.


void extractSubstring(char strMain[100],int startPosition,int lengthOfstring){


    char temp[50];
    int count = 0;

    for(int i = startPosition;i <= startPosition+lengthOfstring;i++){


        temp[count++] = strMain[i];

    }
    temp[count] = '\0';

    printf("-%s-",temp);

}

int main(){

    char strMain[100];
    
    printf("Enter the string:-- ");
    scanf("%[^\n]",strMain);


    int startPosition = 0;
    int lengthOfstring = 0;

    printf("Enter the start Position:-- ");
    scanf("%d",&startPosition);

    printf("Enter the Length of substring:-- ");
    scanf("%d",&lengthOfstring);


    extractSubstring(strMain,startPosition,lengthOfstring);



}