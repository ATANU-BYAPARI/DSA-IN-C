#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size_of_array;
    int top; // is to store pointer value of the stack, i.e. where the last element is present
    int *array;
};
// function to check, if the stack is empty or not
int isEmpty(struct stack *s)
{
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
// function to check, if the stack is full or not
int isFull(struct stack *s)
{
    if(s->top==s->size_of_array-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    struct stack *s;
    s->size_of_array = 50;
    s->top = -1;// means for now there is no element in array
    s->array = (int *)malloc((s->size_of_array) * (sizeof(int))); // memory allocating for array

    // check if the stack is empty or not
    if (isEmpty(s)) // if returnd value is not zero means the statement is true and if zero then the statement is false
    {
        printf("The stack is empty now!\n");
    }
    else
    {
        printf("The stack is not empty!\n");
    }

    //check if the stack is full or not
    if (isFull(s))
    {
        printf("The stack is full now!\n");
    }
    else
    {
        printf("The stack is not full!\n");
    }
}