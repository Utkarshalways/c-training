#include<stdio.h>
#include<string.h>
#include <ctype.h>


int checkSubstringPresent(char *str,char *substr){

    int index = 0;
    int startingIndex = -1;

    for(int i = 0;i<str[i] != '\0';i++){

        if(index < strlen(substr)){

        if(str[i] == substr[index]){
            if(str[i-1] != substr[index-1]){
            startingIndex = i;

            }
            index++;

        }else{

            index = 0;
            startingIndex = -1;
        }


        }
    }

}


int wordsWithoutSpaces(char* str){

    char temp[100][100];
    int rows = 0;
    int count = 0;


    for(int idx = 0;idx < strlen(str);idx++){

          while(!isspace(str[idx]) && isalnum(str[idx])){

            if(!isspace(str[idx]) && isalnum(str[idx])){

             temp[rows][count++] = str[idx++];

            }
            else{
                
                rows++;
                count = 0;
                idx++;
          }
            }

          }
          

        for(int idx = 0;idx<rows;idx++){

                printf("\n%s",temp[idx]);

        }

}





int countOfWords(char* str){


        int count = 0;

        // printf("%d",strlen(str));
        for(int i = 0;i<str[i] != '\0';i++){

            

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
    char* substr;

    printf("Enter the main String:-- ");
    scanf("%[^\n]",str);

    // printf("%s",str);

    // printf("Enter the substring:-- ");
    // scanf("%[^\n]",substr);


    printf("%d",countOfWords(str));
    wordsWithoutSpaces(str);
    // countOfWords()

}