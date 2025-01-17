#include<stdio.h>
#include<ctype.h>
#include<string.h>

int countOfWords(char* str){


        int count = 0;

        
        for(int i = 0;i<strlen(str);i++){

            if(str[i] != ' '){

                while(str[i] != ' '){
                    i++;
                }
                
                count++;

            }

        }

        return count;

        
}

int main(){

    char str[100];
    
    printf("Enter the main String:-- ");
    scanf("%[^\n]",str);
    printf("%d",countOfWords(str));
   
}