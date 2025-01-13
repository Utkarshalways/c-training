#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include  <ctype.h>


int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}


void printing3Sum(int arr[],int arrSize){

        printf("[[");
        int count = 0;

        for(int idx = 0;idx<arrSize;idx++){
            
            
            if(count == 3 && idx < arrSize){

                
                        printf("%d ",arr[idx]);
                        printf("],[");
                        count = 0;

            }
            else{
                
                printf("%d",arr[idx]);
            }
            count++;

            
            

        }
        printf("]]");

}




void ThreeSum(int arr[],int arrSize){
        

        qsort(arr, arrSize, sizeof(int), cmp);

        int temp[100];

        int count = 0;

        for(int idx = 0;idx<arrSize-2;idx++){

            if(idx == 0 ||  arr[idx] != arr[idx-1]){


            int start = idx+1;
            int end = arrSize-1;

            while(start < end){


                if((arr[start] + arr[end] + arr[idx]) == 0){

                        temp[count++] = arr[idx];
                        temp[count++] = arr[start];
                        temp[count++] = arr[end];
                        start++;
                        end--;

                        while(start < end && arr[start] == arr[start-1]){
                            start++;
                        }
                        
                }
                else if(arr[start] + arr[end] + arr[idx] > 0){
                    end--;
                }
                else{

                    start++;
                }
                }
            }
        }

        printing3Sum(temp,count);
}

int main() {

    // printf("Enter The String:-- ");
    char str[100];
    scanf("%[^\n]",str);
    

    // printf("Enter it ");

    // printf("%s",str);
    int arr[100];
    int count = 0;

    for(int idx = 1;idx<strlen(str);idx++){

             if(str[idx] == '-' && isdigit(str[idx+1])){
                int num = 0;
                idx++;
                while(isdigit(str[idx])){


                    num = num * 10 + (str[idx] - '0');
                    // printf(" num in first loop :- %d\n",num);
                    idx++;

                }

                // printf("\n");
                // printf("\n");
                // printf("\n");
                arr[count++] = -num;

            }
            else if( str[idx] >= '0' && str[idx] <= '9'){


                int num =0;
                while(isdigit(str[idx])){


                    num = num * 10 + (str[idx++] - '0');
                    // printf(" num in second loop :- %d",num);

                }
                arr[count++] = num;

            }

          
            


    }




    ThreeSum(arr,count);


    


    

    
    return 0;
}
