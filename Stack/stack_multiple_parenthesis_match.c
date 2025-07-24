#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    char *array;
    int top;
};
void push(struct stack *s, char data)
{
    s->top++;
    s->array[s->top] = data;
}
int pop(struct stack *s, char char_data)
{
    if (s->top == -1)
    {
        printf("Parenthesis %c not matched!", char_data);
        return -1;
    }
    else if (char_data == ')' && s->array[s->top] == '(')
    {
        s->top--;
        return 0;
    }
    else if (char_data == ']' && s->array[s->top] == '[')
    {
        s->top--;
        return 0;
    }
    else if (char_data == '}' && s->array[s->top] == '{')
    {
        s->top--;
        return 0;
    }
    else{
        printf("Parenthesis %c not matched!",char_data);
        return -1;
    }
}
void isEmpty(struct stack* s){
    if(s->top==-1){
        printf("All parenthesis matched!");
    }
    else{
        printf("Parenthesis %c not matched!",s->array[s->top]); // great suggestion from chatGPT as i was passing char_data from calling but if s->top is -1 then there is no data so instead of this the data will be handeled here properly
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    printf("Enter the expression: ");
    char arr[50];
    scanf("%s", arr);

    int x = strlen(arr) + 1;
    s->array = (char *)malloc(x * sizeof(char));
    int i = 0;
    int y=0;
    while (arr[i] != '\0')

    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            push(s, arr[i]);
            i++;
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            y = pop(s, arr[i]);
            i++;
            if (y == -1)
            {
                break;
            }
        }
        else
        {
            i++;
        }
    }
    if(y==0){
        isEmpty(s);
    }
    free(s->array);
    free(s);
}