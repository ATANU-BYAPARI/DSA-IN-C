// modify it for braces also
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    char *array;
    int top;
};
void pop(struct stack *s)
{
    if (s->top != -1)
    {
        s->top--;
    }
}
int check_precedence(char data, struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        int old_data = 0;
        int new_data = 0;
        if (s->array[s->top] == '+' || s->array[s->top] == '-')
        {
            old_data = 0;
        }
        if (s->array[s->top] == '*' || s->array[s->top] == '/')
        {
            old_data = 1;
        }
        if (data == '-' || data == '+')
        {
            new_data = 0;
        }
        if (data == '*' || data == '/')
        {
            new_data = 1;
        }
        if (new_data > old_data)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void push(struct stack *s, char data)
{
    s->top++;
    s->array[s->top] = data;
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;

    char str[50];
    char str_in_to_po[50];
    printf("Enter the expression: ");
    scanf("%s", str);

    int len = strlen(str) + 1;
    s->array = (char *)malloc(len * sizeof(char));

    int idx = 0;
    int new_idx = 0;

    while (str[idx] != '\0')
    {
        if (str[idx] == '-' || str[idx] == '+' || str[idx] == '*' || str[idx] == '/')
        {
            int store = check_precedence(str[idx], s);
            if (store == 1)
            {
                push(s, str[idx]);
                idx++;
            }
            else
            {

                while (s->top != -1)
                {
                    str_in_to_po[new_idx] = s->array[s->top];
                    pop(s);
                    new_idx++;
                }
                idx++;
            }
        }
        else
        {
            str_in_to_po[new_idx] = str[idx];
            new_idx++;
            idx++;
        }
    }
    while (s->top != -1)
    {
        str_in_to_po[new_idx] = s->array[s->top];
        pop(s);
        new_idx++;
    }
    str_in_to_po[new_idx] = '\0';

    printf("After postfix: %s", str_in_to_po);
    free(s->array);
    free(s);
    return 0;
}