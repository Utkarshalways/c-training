#include <stdio.h>
#include<stdlib.h>
#define MaxLen 50


void printMatrix(int matrix[][100],int matrixSize){

    for(int row = 0;row<matrixSize;row++){

        for(int col = 0;col < matrixSize;col++){

            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }

}



void cofactor(int mat[MaxLen][MaxLen],int temp[MaxLen][MaxLen],int row,int col, int matSize){

    int idx = 0;
    int secIdx = 0;

    for(int r = 0;r<matSize;r++){


        for(int c = 0;c<matSize;c++){

            if(row != r && c  != col){

                temp[idx][secIdx++] = mat[r][c];

                if(secIdx == matSize-1){

                    secIdx = 0;
                    idx++;

                }   

            }

        }

    }

}


int determinantofMatrix(int mat[MaxLen][MaxLen],int matSize){



    if(matSize == 1){
        return mat[0][0];


    }
    

    int res = 0;
    int is_Positive = 1;

    int temp[MaxLen][MaxLen];


    

            for(int c = 0;c<matSize;c++){

                cofactor(mat,temp,0,c,matSize);


                res += is_Positive * mat[0][c] * determinantofMatrix(temp,matSize-1);

                is_Positive  = -is_Positive;


            }


    return res;
    


}


int main(){

    int mat[MaxLen][MaxLen];
    int rowArr1 = 0;
    int colArr1 = 0;

    printf("Enter the No. of Rows (1):--");
    scanf("%d",&rowArr1);
    printf("Enter the No. of cols (1):--");
    scanf("%d",&colArr1);

    printf("Enter the Matrix:-- \n");
    for(int r = 0;r<rowArr1;r++){

        for(int c = 0;c<colArr1;c++){

            scanf("%d",&mat[r][c]);

        }

    }
    //1, 0, 2, -1
    //3, 0, 0, 5
    //2, 1, 4, -3
    //1, 0, 5, 0



    printf("%d",determinantofMatrix(mat,rowArr1));



    

    return 0;

}