// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

int main() {
    // Write C code here
    char str[100];
    printf("Enter the String:--");
    scanf("%s",str);
    
    int k = 0;
    scanf("%d",&k);
    
    for(int j = 0;j <  k ;j++){
        
    
    char p = str[0];
    
    for(int i =1;i<strlen(str);i++){
        
        
        str[i-1] = str[i];
        
    }
    
    str[strlen(str)-1] = p;
    printf("%s\n",str);
    }
    
    
    // printf("%s\n",str);
    
    
    

    return 0;
}