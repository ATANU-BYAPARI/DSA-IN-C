#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void print_linked_list(struct node *ptr)
{
    while (ptr != NULL) // until ptr not hitting NULL 
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next; // moving pointer to the next pointer
    }
}
struct node* delete_last(struct node *head)
{
    struct node *ptr = head; // storing head pointer
    while(ptr->next->next!=NULL){ // while next to ptr->next is not null
        ptr=ptr->next; // moving ptr to next ptr
    }
    free(ptr->next); // freeing the memory of ptr->next, or the node to be deleted  
    ptr->next=NULL; // setting current node to NULL
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));   // creating and allocating memory of head
    struct node *second = (struct node *)malloc(sizeof(struct node)); // creating and allocating memory of second
    struct node *third = (struct node *)malloc(sizeof(struct node));  // creating and allocating memory of third
    struct node *fourth = (struct node *)malloc(sizeof(struct node)); // creating and allocating memory of fourth
    struct node *fifth = (struct node *)malloc(sizeof(struct node));  // creating and allocating memory of fifth

    head->data = 1;   // setting data of head
    second->data = 2; // setting data of second
    third->data = 3;  // setting data of third
    fourth->data = 4; // setting data of fourth
    fifth->data = 5;  // setting data of fifth

    head->next = second;  // setting pointer of second to head
    second->next = third; // setting pointer of third to second
    third->next = fourth; // setting pointer of fourth to third
    fourth->next = fifth; // setting pointer of fifth to fourth
    fifth->next = NULL;   // setting pointer of NULL to fifth

    delete_last(head); // passing head linked node
    print_linked_list(head); // printing the total new linked list
}