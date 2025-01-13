#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int compareString(char* str,char* str2){
    
    
    
    if(strlen(str) != strlen(str2)){
        
        return 0;
    }
    
    
    int start = 0;
    int end = strlen(str);
    
    while(start < end){
        
        
        if(str2[start] == str[start] && str[end] == str2[end]){
            
            start++;
            end--;
        }
        else{
            
            return 0;
        }
    }
    
    
    return 1;
    
    
    
    
    
}


void newString(char* str,char* str2){
    
    // char *arr = (char*) malloc(sizeof(char)*strlen(str));
    
    int count = 0;
    for(int i = 0;i<strlen(str);i++){
        
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' ){
            
           str2[count++] = str[i];
            
        }
        
    }
    
    // printf("%s\n",arr);
    
    // return arr;
    
}


int main(){
    
    // char str[MAX_SPACE];
    
    // char* str =(char*) malloc(30*sizeof(char));
    char str1[100];
    char str2[100];
    // char* str;
    
    
    printf("Enter the String 1 :- ");
    fgets(str1,sizeof(str1),stdin);
    // scanf("%s",str1);
    printf("\n");
   
     newString(str1,str2);
    
    
    printf("%s",str2);
    
    // printf("%s\n",str);
    
    
    
    
    
    return 0;
    
}



// Online C compiler to run C program online
#include <stdio.h>


void printArray(int *arr,int n){
    
    printf("\n---Start Printing---\n");
    
    for(int i = 0;i<n;i++){
        
        printf("%d",arr[i]);
    }
    
    printf("\n--Done Printing--\n");
    
}

void reverseOrder(int arr[],int n){
    
    int start = 0;
    int end = n-1;
    
    while(start < end){
        
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
        
    }
    
    printArray(arr,n);
    
    
    
    
}

int main() {
   
   
   int arr[] = {1,23,2,32};
   int n = sizeof(arr)/sizeof(int);
   
   printArray(arr,n);
   
   
   reverseOrder(arr,n);
   
   
   printArray(arr,n);
   
   

    return 0;
}