#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};
void linked_list_last(struct node*  n6){
    struct node* ptr=n6;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->previous;
    }
}
void linked_list_first(struct node*  head){
struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->previous = NULL;
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    head->next = n1;
    n1->data = 1;
    n1->previous = head;
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    n1->next = n2;
    n2->data = 2;
    n2->previous = n1;
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n2->next = n3;
    n3->data = 3;
    n3->previous = n2;
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    n3->next = n4;
    n4->data = 4;
    n4->previous = n3;
    struct node *n5 = (struct node *)malloc(sizeof(struct node));
    n4->next = n5;
    n5->data = 5;
    n5->previous = n4;
    struct node *n6 = (struct node *)malloc(sizeof(struct node));
    n5->next = n6;
    n6->data = 6;
    n6->previous = n5;
    n6->next = NULL;

    printf("Linked list from head: \n");
    linked_list_first(head);
    printf("Linked list from last: \n");
    linked_list_last(n6);
    return 0;
}