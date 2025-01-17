#include<stdio.h>
#include<string.h>
#include<ctype.h>


char* removeDuplicates(char* str){

    int index = 0;
    char* newStr;

        for(int idx = 0;idx < strlen(str);idx++){

            int secIdx;
            for( secIdx = 0;secIdx < idx;secIdx++){

                    if(str[idx] == str[secIdx]){

                        break;

                    }
                   

            }
             if(secIdx == idx){

                        str[index++] = str[idx];
            }

        }

    	str[index] = '\0';

        printf("%s\n",str);

        // return newStr;
        return str;
}

int main(){

        printf("Enter the String:-- ");
        char *str;
        scanf("%s",str);
        
        printf("\n");
        char* newStr = removeDuplicates(str);

        printf("%s",newStr);


}