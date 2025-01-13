#include <stdio.h>


void printMatrix(int arr[][3],int n,int m){
    
    
        for(int i = 0;i<n;i++){
            
            for(int j =0;j<m;j++){
                
                printf("%d ",arr[i][j]);
            }
            
            printf("\n");
        }
    
}

int main() {
    
    
    int m = 3;
    int n = 3;
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    
    
    printMatrix(arr,3,3);
    
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;
    
    
    while(top <= bottom && left <= right){
        
        for(int i = left;i <= right;i++){
            
            printf("%d ",arr[top][i]);
            
        }
        top++;
        
        for(int i = top; i <= bottom;i++){
            
            printf("%d ",arr[i][right]);
        }
        right--;
        
        for(int i = right;i >= left;i--){
            
            printf("%d ",arr[bottom][i]);
            
        }
        bottom--;
        
        for(int i = bottom;i >= top ;i--){
            
            printf("%d ",arr[i][left]);
        }
        
        left++;
        
        
    }
        
    
    
    
    

    return 0;
}