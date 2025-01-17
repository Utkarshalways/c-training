#include<stdio.h>
#include<string.h>
#include<ctype.h>


char* removeInstances(char str[],char newStr[],int strLen,char remove){

        
        int index = 0;

        for(int idx = 0;idx < strLen;idx++){

            if(str[idx] == remove){
                continue;
            }
            else{

                newStr[index++] = str[idx];
            }

        }

        return newStr;
}



int main(){
    char newStr[100];
    char str[100];
    char remove;
    printf("Enter the String:-- ");
    scanf("%[^\n]%*c",str);
    
    printf("char:-");
    scanf("%c",&remove);

    printf("%s",removeInstances(str,newStr,strlen(str),remove));

}