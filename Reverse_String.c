#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reversestring(char str[], int length);

int main()
{

    char ch, str[] = "hello"; // Example string. Change as desired.
    int length = strlen(str);

    if (length < 1 || length > 10000)
    {

        printf("Invalid string. Length must be between 1 and 10^5");
        return 1;
    }
    for (int i = 0; i < length - 1; i++)
    {

        if (str[i] < 32 || str[i] > 126)
        {
            printf("Invalid string. Not a printable Ascii character.");
            return 2;
        }
    }

    printf("Input String: %s\n\n", str);

    reversestring(str, length);

    return 0;
}

void reversestring(char str[], int length)
{
    char ch;

    printf("Reversed String: ");
    for (int i = 0, j = length - 1; i < length && i != j; i++, j--)
    {

        ch = str[j];
        str[j] = str[i];
        str[i] = ch;
    }

    for (int i = 0; i < length; i++)
    {

        printf("%c", str[i]);
    }
}