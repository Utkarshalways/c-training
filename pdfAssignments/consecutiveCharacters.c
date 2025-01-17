#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *removeDuplicates(char *str)
{

    int index = 0;
    char *newStr;

    for (int idx = 0; idx < strlen(str); idx++)
    {

        int secIdx;
        for (secIdx = 0; secIdx < idx; secIdx++)
        {

            if (str[idx] == str[secIdx])
            {

                break;
            }
        }
        if (secIdx == idx)
        {

            str[index++] = str[idx];
        }
    }

    str[index] = '\0';

    // printf("%s\n",str);

    // return newStr;
    return str;
}

void stringUpdate(char *str)
{

    int arr[255] = {0};

    for (int i = 0; i < strlen(str); i++)
    {

        arr[str[i]] += 1;
    }

    char *res = removeDuplicates(str);

    for (int i = 0; i < strlen(res); i++)
    {

        printf("%c%d", res[i], arr[res[i]]);
    }
}



char* someFunction(char *str)
{

    char *temp = (char *)malloc(sizeof(char) * strlen(str));
    int index = 0;

    for (int i = 0; i < strlen(str); i++)
    {

        int count = 0;
        temp[index++] = str[i];
        printf("%c", str[i]);
        if (i != strlen(str))
        {
            while (str[i] == str[i + 1])
            {
                count++;
                i++;
            }
        }
        count++;

        if (count > 1)
        {   char *ptr = temp+index;
            char* anothertemp = (char*) malloc(sizeof(char)*strlen(str)); 
              sprintf(anothertemp, "%d", count);
              while(*anothertemp != '\0'){

                *ptr = *anothertemp;
                ptr++;
                anothertemp++;
              }
            index++;
            printf("%d", count);
        }
    }
    printf("\n");


    *(temp+index) = '\0';
    return temp;
}

int main()
{

    char str[100];
    printf("INput:--");
    scanf("%s", str);

    // stringUpdate(str);
    printf("%s",someFunction(str));
}