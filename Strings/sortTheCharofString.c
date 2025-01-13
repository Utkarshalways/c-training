#include<stdio.h>


void sorttheString(char* str){

            for(int i = 0;str[i] != '\0';i++){

                for(int j  = i+1;j<str[j] != '\0';j++){

                    if(str[i] > str[j]){

                        char temp = str[i];
                        str[i] = str[j];
                        str[j] = temp;
                    }

                }

            }


            printf("%s",str);

}

int main(){

    printf("Enter the String:-- ");
    char* str ;
    scanf("%[^\n]",str);


    sorttheString(str);

}