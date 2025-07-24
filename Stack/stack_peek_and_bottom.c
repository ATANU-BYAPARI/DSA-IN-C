#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// i used static so that its value does not change during a function call untill i change it
//static int top = -1; // global declaration for deal with the complexity of null head creation---> by me
// top is only necessory in array based linked list

void isFull(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("The stack is full!");
        // if head is null it is not necessory to free(head), although it is safe to free but not recomended
    }
    else{
        printf("The stack is not full!\n");
        free(head);
    }
}
void print(struct node *head)
{
    struct node *str = head;
    while (str!=NULL)
    {
        printf("data: %d\n", str->data);
        str = str->next;
    }
}
struct node *push(struct node *head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}
int isEmpty(struct node* head)
{
    if (head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void  peek(struct node* head){
    if(!isEmpty(head)){
printf("Top data: %d\n",head->data);
    }
}
void bottom(struct node* head){
    struct node* str=head;
    if(!isEmpty(str)){
        while(str->next!=NULL){
            str=str->next;
        }
        printf("Bottom data: %d\n",str->data);
    }
    else{
        printf("The stack is empty!");
        exit(1); // exit(0) means no error
    }
}
int main()
{
    struct node *head = NULL; // creating an empty list, no memory is allocated so head is not exist in real
    int x=isEmpty(head);
    if(x==1){
        printf("Stack is Empty!\n");
    }
    if(x==0){
        printf("Stack is not empty!\n");
    }
    head = push(head, 6);
    head = push(head, 7);
    head = push(head, 8);
    head = push(head, 9);
    print(head);
    isFull();
    peek(head);
    bottom(head);
    return 0;
}