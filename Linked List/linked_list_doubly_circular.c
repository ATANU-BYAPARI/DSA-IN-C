#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* previous;
    struct node *next;
};
void print_linked_list_using_next(struct node *head)
{
    // traversing the doubly circular linked list
    struct node *ptr = head;
    while (ptr->next != head)
    {
        printf("data: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("data: %d\n", ptr->data); //for handling last data
}
void print_linked_list_using_previous(struct node *fourth)
{
    // traversing the doubly circular linked list
    struct node *ptr = fourth;
    while (ptr->previous != fourth)
    {
        printf("data: %d\n", ptr->data);
        ptr = ptr->previous;
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

    // setting next pointers
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; //this is the looping condition

    //setting previous pointers
    first->previous=head;
    second->previous=first;
    third->previous=second;
    fourth->previous=third;
    head->previous=fourth; //this is the looping condition

    //doubly circular linked list creation has been done above

    printf("Linked list traversal from head node: \n");
    print_linked_list_using_next(head);
    printf("Linked list traversal from last node: \n");
    print_linked_list_using_previous(fourth);
    return 0;
}