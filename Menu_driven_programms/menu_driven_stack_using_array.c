// i)Write a C program to implement stack using array

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top;
};
void stack_top(struct stack* stack){
    if(stack->top==-1){
        printf("Stack underflow!\n");
        return;
    }
    printf("Stack top data: %d\n",stack->arr[stack->top]);
    return;
}
void isFull(struct stack *stack)
{
    if (stack->top >= stack->size - 1)
    {
        printf("The stack is full!\n");
        return;
    }
    printf("The stack is not full!\n");
    return;
}
void isEmpty(struct stack *stack)
{
    if (stack->top == -1)
    {
        printf("The stack is empty!\n");
        return;
    }
    printf("The stack is not empty!\n");
    return;
}
void peek(struct stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    int x = stack->top;
    while (x >= 0)
    {
        printf("%d ", stack->arr[x]);
        x--;
    }
    return;
}
void push(struct stack *stack, int data)
{
    if (stack->top >= stack->size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
    return;
}
void pop(struct stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow!\n");
        return;
    }
    stack->top--;
    return;
}
int main()
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    if (stack == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    int size;
    printf("Enter your stack size: ");
    scanf("%d", &size);
    stack->size = size;
    stack->arr = (int *)malloc(size * sizeof(int));
    if (stack->arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 2;
    }
    stack->top = -1;
    char check_point = 'n';
    do
    {
        printf("Enter 1: To push data into the stack\nEnter 2: To pop data from the stack\nEnter 3: To peek the stack\nEnter 4: To see if, the stack is empty or not\nEnter 5: To see if, the stack is full or not\nEnter 6: To see the top element in the stack\n");
        int show;
        scanf("%d", &show);
        switch (show)
        {
        case 1:
        {
            char check = 'n';
            do
            {
                int data;
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(stack, data);
                fflush(stdin);
                printf("Want to enter another data (y/n): ");
                check = getchar();
            } while (check == 'y');
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
        }
        break;
        case 2:
        {
            char check = 'n';
            do
            {
                if (stack->top != -1)
                    printf("Data removed: %d\n", stack->arr[stack->top]);
                pop(stack);
                fflush(stdin);
                printf("Want to remove another data (y/n): ");
                check = getchar();
            } while (check == 'y');
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
        }
        break;
        case 3:
        {
            peek(stack);
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
        }
        break;
        case 4:
        {
            isEmpty(stack);
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
        }
        break;
        case 5:
        {
            isFull(stack);
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
        }
        break;
        case 6:
        {
            stack_top(stack);
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
        }
        break;
        default:
            printf("Please select a valid option!\n");
            printf("Want to perform more operations? (y/n): ");
            fflush(stdin);
            check_point = getchar();
            free(stack->arr);
            free(stack);
            return 0;
        }
    } while (check_point == 'y');

    free(stack->arr);
    free(stack);
}