// 7. Write a program in C to count the total number of alphabets, digits and special characters in a string.

// Test Data :
// Input the string : Welcome to w3resource.com

// Expected Output :

// Number of Alphabets in the string is : 21 
// Number of Digits in the string is : 1 
// Number of Special characters in the string is : 4 

#include<stdio.h>


void countOnString(char* str,int alpha,int digit,int spch){

    for(int i = 0;str[i] != '\0';i++){

        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){


            alpha++;

        }
        else if(str[i] >= '0' && str[i] <= '9' ){

            digit++;
            
        }
        else{

            spch++;
        }

    }

    printf("Aplhabets :- %d\nDigits:-- %d\nSpecialCharacters:-- %d",alpha,digit,spch);

}

int main(){

    printf("Enter the String:-- ");
    char *str;
    scanf("%[^\n]%*c",str);


    int alpha = 0;
    int digit = 0;
    int specialChar = 0;    

    countOnString(str,alpha,digit,specialChar);

    // printf("Aplhabets :- %d\nDigits:-- %d\nSpecialCharacters:-- %d",alpha,digit,specialChar);

}