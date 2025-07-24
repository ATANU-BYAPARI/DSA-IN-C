#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size_of_array;
    int top;
    int *array;
};

void peek(struct stack *s, int top)
{
    if (top < 0 || top>s->size_of_array)
    {
        printf("Invalid position!");
        exit(-1);
    }
    else
    {
        printf("The element at position %d is %d\n", top + 1, s->array[top]);
    }
}
void push(struct stack *s, int data)
{ // adding data inside
    if (s->top == s->size_of_array - 1)
    {
        printf("Stack OverFlow!\n"); // i.e. stack is full
    }
    else
    {
        s->top++;
        s->array[s->top] = data;
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); // allocating the memory space for stack pointer
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

    for (int j = 0; j <=s->top; j++)
    {
        peek(s, j);
    }

    free(s->array);
    free(s);
    // to free the alocating memory
}