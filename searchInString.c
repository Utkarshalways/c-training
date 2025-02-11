#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>

int searchINString(char* str,char* part){

        
    for(int i = 0;i<strlen(str);i++){
        
        int start = i;
        int idx = 0;

        while(str[start] == part[idx]  && start <= strlen(str) && idx <= strlen(part)){
            
                start++;
                idx++;

                if(start <= strlen(str) && idx <= strlen(part)){
                    return i;
                }
        }
        if(idx == strlen(part)){
            
            return i;
        }
    }

    return -1;

}

char* removeOccurrences(char* s,char* part){

    int res = searchINString(s,part);
    if(res == -1){
        return s;
    }
    
    int lenS = strlen(s);
    int lenPart = strlen(part);
    if(lenS < lenPart){
        return s;
    }
    else if(lenS == lenPart){

        if(strcmp(lenS,lenPart)== 0){
            return "";
        }
        else{
            return s;
        }
    }
    int newLen = (lenS - lenPart) * sizeof(char);
    int startIndex;
    char *result = (char *)malloc((lenS + 1) * sizeof(char));
    while(newLen >= startIndex){
        
    }
    return removeOccurrences(result,part);

}

int main(){

    char str[100];
    scanf("%s",str);

    // printf("%s",str);
    char part[100];
    scanf("%s",part);

    // printf("%d\n",searchINString(str,part));
    printf("%s",removeOccurrences(str,part));
}