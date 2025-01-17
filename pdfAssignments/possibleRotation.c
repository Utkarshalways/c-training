#include<stdio.h>
#include <string.h>


int checkRotations(char* str,char* checkstr){

    if(strlen(str) != strlen(checkstr)){
        return 0;
    }

    for(int idx = 0;idx < strlen(str);idx++){

        int secIdx;
        for(secIdx = 0;secIdx < strlen(str);secIdx++){

            if(str[idx+secIdx % strlen(str)] != checkstr[secIdx]){

                break;
            }

        }

        if(secIdx == strlen(str)){
            return 1;
        }

    }

    return 0;

}



int checkitBrute(char* str , char* checkstr){

    
    for(int i = 0;i<strlen(str);i++){

        int temp = str[0];

        for(int j = 1;j<strlen(str);j++){

            str[j-1] = str[j];

        }
        str[strlen(str)-1] = temp;


        if(strcmp(str,checkstr)==0){
            return 1;
        }

    }

    return 0;
}

int main(){


    char str[100];
    printf("Enter the string:--");
    scanf("%s",str);

    char checkstr[100];
    printf("Enter the string you want to check:--");
    scanf("%s",checkstr);


    printf("%d",checkitBrute(str,checkstr));



}