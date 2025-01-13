// Write a program in C to find the maximum number of characters in a string.
#include<stdio.h>
#define MaxChar 255

void calculateFrequency(char* str){

    int charFreq[MaxChar];

    for(int i = 0;i<MaxChar;i++){

        charFreq[i] = 0;
    }
    

    for(int i = 0;str[i] != '\0';i++){

        int ascii = (int)str[i];
        charFreq[ascii]++;

    }

    int max  = 0;

    for(int  i = 0;i < MaxChar;i++){

        if(i != 32){
            if(charFreq[i] > charFreq[max]){

                max = i;

            }
        }
    }


    printf("The highest Freqency is of %c and that is %d.",max,charFreq[max]);

}


int main(){


    char* str;
    printf("Enter the string:-- ");
    scanf("%[^\n]",str);

    calculateFrequency(str);



}