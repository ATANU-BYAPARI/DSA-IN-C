#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size_of_array;
    int top;
    int *array;
};

void bottom(struct stack *s)
{
    printf("The bottom most value of the stack is: %d\n", s->array[0]);
}
void top(struct stack *s)
{
    printf("The top most value of the stack is: %d\n", s->array[s->top]);
}
void push(struct stack *s, int data)
{
    if (s->top == s->size_of_array - 1)
    {
        printf("Stack OverFlow!\n");
    }
    else
    {
        s->top++;
        s->array[s->top] = data;
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size_of_array = 50;
    s->top = -1;
    s->array = (int *)malloc((s->size_of_array) * (sizeof(int)));
    int data = 6;
    push(s, data + 1);
    push(s, data + 2);
    push(s, data + 3);
    push(s, data + 4);
    push(s, data + 5);
    push(s, data + 6);
    push(s, data + 7);
    push(s, data + 8);
    push(s, data + 9);
    if (s->top >= 0 && s->top <= s->size_of_array) // if i use "top" in place of "s->top" then also code is running why?
    {
        bottom(s);
        top(s);
    }

    free(s->array);
    free(s);
}