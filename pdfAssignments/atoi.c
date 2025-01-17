#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>

int stringToNum(char* str){


        int num = 0;
        int is_negative = 0;
        
        if(!isdigit(str[0]) && str[0] != '-' && str[0] != '+' || (!isdigit(str[1]))){
            return 0;
        }
        

        for(int idx = 0;idx<strlen(str);idx++){
            int tempNum = 0;
            if( str[idx] == '-' && isdigit(str[idx+1]) || isdigit(str[idx]) ){


                if(str[idx] == '-'){
                    is_negative = 1;
                    idx++;
                }
                while(isdigit(str[idx])){

                    tempNum = tempNum * 10 + str[idx] - '0';
                    idx++;
                }

                if(is_negative == 1){

                    num = -tempNum;

                }
                else{

                    num = tempNum;
                }
                
            }
            

        }
        
        return num;



}


int main(){

    printf("Enter the String: ");
    char* str;
    scanf("%s",str);
    
    printf("This is preBuild atoi Function Result: %d\n",atoi(str));

    printf("The result in Number is: ");
    printf("%d",stringToNum(str));

}