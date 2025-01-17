#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkSubstringPresent(char *str, char *substr)
{

    int startingIndex = -1;

    for (int i = 0; i < strlen(str); i++)
    {
        int index = 1;
        startingIndex = i;
        while (str[startingIndex] == substr[index])
        {
            startingIndex++;
            index++;
        }
        if (index > strlen(substr))
        {
            return i - 1;
        }
        else if (index == strlen(substr))
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    char str[100];
    char substr[100];

    printf("Enter the main String:-- ");
    scanf("%[^\n]", str);

    printf("Enter the SubString:-- ");
    scanf("%s", substr);

    printf("%d", checkSubstringPresent(str, substr));

    return 0;
}