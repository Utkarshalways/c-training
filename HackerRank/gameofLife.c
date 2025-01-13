#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){

printf("Enter The String:-- ");
    char str[100];
    scanf("%[^\n]",str);
    

    int arr[100][100];
    int col = 0;
    int totalCol = 0;
    int row = 0;

    for(int idx = 1;idx<strlen(str)-1;idx++){

            
            if( str[idx] >= '0' && str[idx] <= '1'){

                  int num = str[idx] - '0';
                  printf("num at %d,%d :--  %d\n",row,col,num);
                  arr[row][col] = num;
                  printf("arr :--  %d\n",arr[row][col]);
                  col++;

            }
            else if(str[idx] == ']'){
                totalCol = col;
                row++;
                col = 0;
            }

    }

    printf("The matrix is :-- \n");

    for(int r = 0;r < row;r++){

        for(int c = 0;c < totalCol;c++){

        printf("%d ",arr[r][c]);

        }

        printf("\n");

    }
}