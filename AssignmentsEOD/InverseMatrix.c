#include<stdio.h>

void printMatrix(int matrix[][100],int matrixSize){

    for(int row = 0;row<matrixSize;row++){

        for(int col = 0;col < matrixSize;col++){

            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }

}

int main(){

    int arr[100][100];
    int arrSize;
    printf("Enter the size of Matrix:-");
    scanf("%d",&arrSize);
    printf("Enter the matrix:- \n");

    for(int row = 0;row<arrSize;row++){

        for(int col= 0;col<arrSize;col++ ){
            scanf("%d",&arr[row][col]);
        }

    }

    printMatrix(arr,arrSize);


}