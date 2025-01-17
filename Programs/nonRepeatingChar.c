// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

int main() {
    
    char str[100];
    printf("Enter the string:--");
    scanf("%[^\n]",str);
    
    char words[100][100];
    int wordcount[100] = {0};
    int count = 0;
    
    
    char* token = strtok(str," ");
    while(token != NULL){
        
        strcpy(words[count],token);
        wordcount[count] = 1;
        count++;
        token = strtok(NULL," ");
    }
    
    for(int i = 0;i<count;i++){
        
        for(int j = i+1;j<count ;j++){
            
            
            if(strcmp("used",words[j])==0){
                continue;
            }
            
            if(strcmp(words[i],words[j])==0){
                    
                    wordcount[i] += 1;
                    strcpy(words[j],"used");
                    //  printf("%s->%d\n",words[i],wordcount[i]);
            }
            
        }
    }
    
    for(int i = 0;i<count;i++){
        
        if(strcmp(words[i],"used")){
            
        
        if(wordcount[i] == 1){
        printf("%s->%d\n",words[i],wordcount[i]);
            return 0;
            
        }
        }
        
    }
    
    
    return 0;
}