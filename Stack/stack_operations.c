#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size_of_array;
    int top;
    int *array;
};
void push(struct stack* s,int data){ // adding data inside
if(s->top==s->size_of_array-1){
    printf("Stack OverFlow!\n"); // i.e. stack is full
}
else
{
    s->top++;
    s->array[s->top]=data;
}
}
void pop(struct stack* s){ // taking out data
if(s->top==-1){
    printf("Stack UnderFlow!\n"); //i.e. stack is empty
    exit(1);
}
else{
    printf("Data is: %d\n",s->array[s->top--]);
}
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack)); // allocating the memory space for stack pointer
    s->size_of_array = 50;
    s->top = -1;
    s->array = (int *)malloc((s->size_of_array) * (sizeof(int)));
    int data=6;
    push(s,data);
    pop(s);

    free(s->array);
    free(s);
    // to free the alocating memory
}