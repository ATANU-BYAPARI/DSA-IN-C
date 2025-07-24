// if it is '(' push into the stack and if this comes ')' pop from the stack
// conditions
// 1. while poping stack must not be empty
// 2. at the end of the program the stack  must be empty
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    // it is to check () this parenthesis
    char *array;
    int size_of_array;
    int top;
};
void push(struct stack *s, char data)
{
    if (s->top >= s->size_of_array-1) // why >= because we are pre incrementing s->top here at 0
    {
        printf("Stack OverFlow!");
        exit(1);
    }
    else
    {
        s->top++; // 0 for reference to above
        s->array[s->top] = data;
    }
}
int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Parenthesis '()' not matched!!");
        return 0;
    }
    else
    {
        s->top--;
        return 1;
    }
}
void isEmpty(struct stack *s)
{
    if (s->top == -1)
        printf("Parenthesis '()' matched!");
    else
        printf("Parenthesis '()' not matched!");
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    char str[3];
    printf("Enter the expression: ");
    scanf("%s", str);
    int x = strlen(str);
    s->size_of_array = x;
    s->array = (char *)malloc(x * sizeof(char));
    s->top = -1;

    int check = 1; // creating check because if already pop() is underflow then  isEmpty() will not be checked!
    for (int i = 0; i < x; i++)
    {
        if (str[i] == '(')
        {
            push(s, '(');
        }

        if (str[i] == ')')
        {
            check = pop(s);
            if (check == 0)
                break;
        }
    }
    if(check!=0)
    {isEmpty(s);} // if only ) is there then it is not pushing into stack so isEmpty() will print parenthesis matched, to avoid it i made this check
    free(s->array);
    free(s);
}