#include<stdio.h>

void printMat(int matSize, int mat[matSize][matSize]) {
    for (int r = 0; r < matSize; r++) {
        for (int c = 0; c < matSize; c++) {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
}


void transpose(int matSize,int mat[matSize][matSize]){

    

    for(int i = 0;i<matSize;i++){

        for(int j = i+1;j<matSize;j++){

                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;

        }
    }

}

void clockwiseRotate(int matSize, int mat[matSize][matSize],int k) {
    

    while( k > 0){


    transpose(matSize,mat);
    


    for(int row = 0;row<matSize;row++){

        int start = 0;
        int end = matSize-1;

        while(start < end){

            int temp = mat[row][start];
            mat[row][start] = mat[row][end];
            mat[row][end] = temp;
            start++;
            end--;

        }

    }
    k--;
    }

    printMat(matSize,mat);
    
}




int main() {
    int matSize = 0;
    printf("Enter the Size :-- ");
    scanf("%d", &matSize);
    int mat[matSize][matSize];
    printf("Enter the matrix:--\n");
    for (int r = 0; r < matSize; r++) {
        for (int c = 0; c < matSize; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    while (1) {
        printf("Enter your Choice:-\n");
        printf("1. clockWise Rotate\n");
        printf("2. AntiClockwise Rotate\n");
      

        int choice;
        scanf("%d", &choice);


        switch (choice) {

        
        case 1:
            printf("Enter K:-- ");
            int k = 0;
            scanf("%d", &k);
            k = k%4;
            clockwiseRotate(matSize, mat,k);
            break;

        case 2:
            printf("Enter K:-- ");
            k = 0;
            scanf("%d", &k);
            k = k%4;
            clockwiseRotate(matSize, mat,4-k);
            break;

        default:
            printf("Please Enter Correct Choice!!!\n");
            return 0;
        }
    }
}
