#include <stdio.h>
#include <string.h>
#include <ctype.h>



char* longestWordUsingtokens(char* str){
    int maxLen = 0;
    char* result;

    char* token = strtok(str," ");
    while(token != NULL){

        printf("token :- %s\n",token);
        if(maxLen <= strlen(token)){
            result = token;
            maxLen =  strlen(token);
        }
        token = strtok(NULL, " ");
    }
    
    printf("Done printing");
    printf("Max length is :--  %d",maxLen);
    return result;


}



int main(){

    char str[300];
    printf("Enter the string:-");
    scanf("%[^\n]",str);


    // longestWord(str);
    printf("%s",longestWordUsingtokens(str));
    return 0;
}

char* longestWord(char* str){

    int length = 0;
    int length_count = 0;
    int starting_index = 0;
    int start = 0;

    for(int idx = 0;idx < strlen(str);idx++){


        if(isalnum(str[idx])){
            start = idx;
            while(str[idx] != ' '){
                length_count++;
                idx++;
            }
            if(length < length_count){
                length = length_count;
                starting_index = start;
            }
            
        }

    }

    printf("there are  %d characters in the longest word",length);

    printf("%s",str[starting_index]);

    return str;

}