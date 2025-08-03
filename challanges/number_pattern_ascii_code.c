#include <stdio.h>
void first_line(int x)
{
    printf("\033[1;31m"); //for green color
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("* * * *  ");
        break;
    case 3:
        printf("* * * *  ");
        break;
    case 4:
        printf("*     *  ");
        break;
    case 5:
        printf("* * * *  ");
        break;
    case 6:
        printf("* * * *  ");
        break;
    case 7:
        printf("* * * *  ");
        break;
    case 8:
        printf("* * * *  ");
        break;
    case 9:
        printf("* * * *  ");
        break;
    case 0:
        printf("* * * *  ");
        break;
    }
    printf("\033[0m");// reset the color
}
// second line ok
void second_line(int x)
{
    printf("\033[1;31m");
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("      *  ");
        break;
    case 3:
        printf("      *  ");
        break;
    case 4:
        printf("*     *  ");
        break;
    case 5:
        printf("*        ");
        break;
    case 6:
        printf("*        ");
        break;
    case 7:
        printf("      *  ");
        break;
    case 8:
        printf("*     *  ");
        break;
    case 9:
        printf("*     *  ");
        break;
    case 0:
        printf("*     *  ");
        break;
    }
    printf("\033[0m");
}
// third line ok
void third_line(int x)
{
    printf("\033[1;37m");
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("      *  ");
        break;
    case 3:
        printf("      *  ");
        break;
    case 4:
        printf("*     *  ");
        break;
    case 5:
        printf("*        ");
        break;
    case 6:
        printf("*        ");
        break;
    case 7:
        printf("      *  ");
        break;
    case 8:
        printf("*     *  ");
        break;
    case 9:
        printf("*     *  ");
        break;
    case 0:
        printf("*     *  ");
        break;
    }
    printf("\033[0m");
}
// fourth line ok
void fourth_line(int x)
{
    printf("\033[1;34m");
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("* * * *  ");
        break;
    case 3:
        printf("* * * *  ");
        break;
    case 4:
        printf("* * * *  ");
        break;
    case 5:
        printf("* * * *  ");
        break;
    case 6:
        printf("* * * *  ");
        break;
    case 7:
        printf("      *  ");
        break;
    case 8:
        printf("* * * *  ");
        break;
    case 9:
        printf("* * * *  ");
        break;
    case 0:
        printf("*     *  ");
        break;
    }
    printf("\033[0m");
}
// fifth line ok
void fifth_line(int x)
{
    printf("\033[1;37m");
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("*        ");
        break;
    case 3:
        printf("      *  ");
        break;
    case 4:
        printf("      *  ");
        break;
    case 5:
        printf("      *  ");
        break;
    case 6:
        printf("*     *  ");
        break;
    case 7:
        printf("      *  ");
        break;
    case 8:
        printf("*     *  ");
        break;
    case 9:
        printf("      *  ");
        break;
    case 0:
        printf("*     *  ");
        break;
    }
    printf("\033[0m");
}
// sixth line ok
void sixth_line(int x)
{
    printf("\033[1;32m");
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("*        ");
        break;
    case 3:
        printf("      *  ");
        break;
    case 4:
        printf("      *  ");
        break;
    case 5:
        printf("      *  ");
        break;
    case 6:
        printf("*     *  ");
        break;
    case 7:
        printf("      *  ");
        break;
    case 8:
        printf("*     *  ");
        break;
    case 9:
        printf("      *  ");
        break;
    case 0:
        printf("*     *  ");
        break;
    }
    printf("\033[0m");
}
// seventh line ok
void seventh_line(int x)
{
    printf("\033[1;32m");
    switch (x)
    {
    case 1:
        printf("*  ");
        break;
    case 2:
        printf("* * * *  ");
        break;
    case 3:
        printf("* * * *  ");
        break;
    case 4:
        printf("      *  ");
        break;
    case 5:
        printf("* * * *  ");
        break;
    case 6:
        printf("* * * *  ");
        break;
    case 7:
        printf("      *  ");
        break;
    case 8:
        printf("* * * *  ");
        break;
    case 9:
        printf("* * * *  ");
        break;
    case 0:
        printf("* * * *  ");
        break;
    }
    printf("\033[0m");
}
int count_digit(int number)
{
    int count = 0;
    while (number != 0)
    {
        count++;
        number /= 10;
    }
    return count;
}
void print_digit(int x)
{
    switch (x)
    {
    case 0:
        printf("* * * *\n*     *\n*     *\n*     *\n*     *\n*     *\n* * * *\n\n");
        break;
    }
}
int main()
{
    unsigned int number;
    printf("Enter a positive number: \n");
    scanf("%u",&number);
    if (number == 0)
    {
        print_digit(number);
        return 0;
    }
    int digit = count_digit(number);
    int store_digit = digit;
    int store_array[digit];
    for (digit; digit > 0; digit--)
    {
        int x = number % 10;
        store_array[digit - 1] = x;
        number /= 10;
    }
    for (int i = 0; i < store_digit; i++)
    {
        first_line(store_array[i]);
    }
    printf("\n");
    for (int i = 0; i < store_digit; i++)
    {
        second_line(store_array[i]);
    }
    printf("\n");
    for (int i = 0; i < store_digit; i++)
    {
        third_line(store_array[i]);
    }
    printf("\n");
    for (int i = 0; i < store_digit; i++)
    {
        fourth_line(store_array[i]);
    }
    printf("\n");
    for (int i = 0; i < store_digit; i++)
    {
        fifth_line(store_array[i]);
    }
    printf("\n");
    for (int i = 0; i < store_digit; i++)
    {
        sixth_line(store_array[i]);
    }
    printf("\n");
    for (int i = 0; i < store_digit; i++)
    {
        seventh_line(store_array[i]);
    }
    printf("\n");
}