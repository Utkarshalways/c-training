#include <stdio.h>
#include <string.h>

void sortString(char *str)
{

    for (int idx = 0; idx < strlen(str); idx++)
    {

        for (int j = 0; j < (strlen(str) - idx) - 1; j++)
        {

            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    str[strlen(str) + 1] = '\0';
}

int checkAnagram(char *str, char *str2)
{

    if (strlen(str) != strlen(str2))
    {
        return 0;
    }

    for (int idx = 0; idx < strlen(str); idx++)
    {

        if (str[idx] != str2[idx])
        {

            return 0;
        }
    }

    return 1;
}

int main()
{

    char str[100];
    printf("Enter the string :-- ");
    scanf("%s", str);
    char str2[100];
    printf("Enter the string 2 :-- ");
    scanf("%s", str2);

    sortString(str);
    sortString(str2);

    printf("%d", checkAnagram(str, str2));
}
