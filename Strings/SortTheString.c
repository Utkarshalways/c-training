#include <stdio.h>
#include <string.h>



void sorttheStrings(char str[][25],int n){


    // printf("It is entering into the function:--");
    char temp[25];

    for(int i = 1;i<=n;i++){


        // printf("Going into loop");


        for(int j = 0;j<n-i;j++){


        if(strcmp(str[j],str[j+1])>0){

                
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);

        }

        }
    }



    for(int i = 0;i<n;i++){

        printf("%s\n",str[i]);

    }
}


int main(){


    printf("Enter Number of String you want:- ");
    int n = 0;
    scanf("%d",&n);


    char str[n][25];
    printf("Enter the Strings:- ");

    


    for(int i = 0;i<n;i++){

        scanf("%s",&str[i]);

    }


    sorttheStrings(str,n);



    


}