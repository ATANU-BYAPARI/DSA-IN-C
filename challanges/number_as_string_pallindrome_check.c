// take number as string input and check if the number is a palindrome or not
#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    char str1[50];
    char strt[50];
    int n = 1; // to chk the initial zeros after - sign
    int p = 0; // to chk the initial zeros
    printf("Enter the number: ");
    scanf("%s", str);
    char *test1(char *, char *); // declaration for copy
    int x = strlen(str);
    if (str[0] == '-' || str[0] == '+')
    {
        for (int g = 1; g < strlen(str); g++) // if all zero then pallindrome
        {
            if (str[g] != '0' && str[g] != '\0')
            {
                goto next;
            }
        }
        printf("The number is pallindrome!");
        return 0;
    }
    if (str[0] != '-' || str[0] != '+')
    {
        for (int h = 0; h < strlen(str); h++)
        {
            if (str[h] != '0' && str[h] != '\0')
            {
                goto next;
            }
        }
        printf("The number is pallindrome!");
        return 0;
    }
    next:
    
    if (str[x - 1] == '0') // number ends with 0 is not a pallindrome except 0 itself,this case is excluded
        printf("The number is not a pallindrome!");
    else
    {
        if (str[0] == '-' || str[0] == '+')
        {
            while (str[n] == '0') // removes initial zeros
            {
                if (str[n] != '0')
                    break;
                n++;
            }
            {
                test1(&str[n], str1); // coping content of str to str1
                test1(&str[n], strt); // coping content of str to strt
                strrev(str1);
                int l = strcmp(str1, strt);
                if (l == 0)
                    printf("The number is a pallindrome");
                else
                    printf("The number is not a pallindrome");
            }
        }
        else
        {
            while (str[p] == '0')
            {
                if (str[p] != '0') // removes initial zeros
                    break;
                p++;
            }
            test1(&str[p], str1);
            test1(&str[p], strt);
            strrev(str1);
            int l = strcmp(str1, strt);
            if (l == 0)
                printf("The number is a pallindrome");
            else
                printf("The number is not a pallindrome");
        }
    }
    return 0;
}
char *test1(char *str, char *str1)
{
    while (*str != '\0')
    {
        *str1 = *str;
        str1++;
        str++;
    }
    *str1 = '\0';
    return str1;
}