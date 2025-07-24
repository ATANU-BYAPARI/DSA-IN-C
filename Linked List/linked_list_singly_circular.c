#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void print_linked_list(struct node *head)
{
    // traversing the singly circular linked list
    struct node *ptr = head;
    while (ptr->next != head)
    {
        printf("data: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("data: %d\n", ptr->data); //for handling last data
}
int main()
{
    // node creation
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    // updating node data
    head->data = 0;
    first->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;

    // setting pointers
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; //this is the looping condition
    // singly circular linked list creation has been done above

    print_linked_list(head);
    return 0;
}