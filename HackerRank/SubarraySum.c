#include<stdio.h>
#include<string.h>
#include<ctype.h>



int kadanceAlgorithm(int arr[],int arrSize){

        int TotalMax = 0;
        int maxTillNow = 0;


        for(int idx = 0;idx < arrSize;idx++){

                maxTillNow += arr[idx];


                if(maxTillNow > TotalMax){

                    TotalMax = maxTillNow;
                }


                if(maxTillNow < 0){
                    maxTillNow = 0;
                }

        }

        printf("%d",TotalMax);

        return TotalMax;


}

int main(){

printf("Enter The String:-- ");
    char str[100];
    scanf("%[^\n]",str);
    

    int arr[100];
    int count = 0;

    for(int idx = 1;idx<strlen(str);idx++){

             if(str[idx] == '-' && isdigit(str[idx+1])){
                int num = 0;
                idx++;
                while(isdigit(str[idx])){


                    num = num * 10 + (str[idx] - '0');
                   
                    idx++;

                }

                
                arr[count++] = -num;

            }
            else if( str[idx] >= '0' && str[idx] <= '9'){


                int num =0;
                while(isdigit(str[idx])){


                    num = num * 10 + (str[idx++] - '0');
                    

                }
                arr[count++] = num;

            }

    }


    for(int idx = 0;idx < count;idx++){

        printf("%d\n",arr[idx]);
    }


    printf("\n%d\n",kadanceAlgorithm(arr,count));



}