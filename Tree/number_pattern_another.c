#include <stdio.h>
void print_digit(int x)
{
    switch (x)
    {
    case 1:
        printf("*\n*\n*\n*\n\n");
        break;
    case 2:
        printf("* * * *\n      *\n      *\n* * * *\n*\n*\n* * * *\n\n");
        break;
    case 3:
        printf("* * * *\n      *\n      *\n* * * *\n      *\n      *\n* * * *\n\n");
        break;
    case 4:
        printf("*     *\n*     *\n*     *\n* * * *\n      *\n      *\n      *\n\n");
        break;
    case 5:
        printf("* * * *\n*\n*\n* * * *\n      *\n      *\n* * * *\n\n");
        break;
    case 6:
        printf("* * * *\n*\n*\n* * * *\n*     *\n*     *\n* * * *\n\n");
        break;
    case 7:
        printf("* * * *\n      *\n      *\n      *\n      *\n      *\n      *\n\n");
        break;
    case 8:
        printf("* * * *\n*     *\n*     *\n* * * *\n*     *\n*     *\n* * * *\n\n");
        break;
    case 9:
        printf("* * * *\n*     *\n*     *\n* * * *\n      *\n      *\n* * * *\n\n");
        break;
    case 0:
        printf("* * * *\n*     *\n*     *\n*     *\n*     *\n*     *\n* * * *\n\n");
        break;
    }
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
int main()
{
    int number = 453;
    if (number == 0)
    {
        print_digit(number);
        return 0;
    }
    int digit = count_digit(number);
    int store_digit=digit;
    int store_array[digit];
    for (digit; digit > 0; digit--)
    {
        int x = number % 10;
        store_array[digit-1]=x;
        number /= 10;
    }
    for(int i=0;i<store_digit;i++){
        print_digit(store_array[i]);
    }
    return 0;
}