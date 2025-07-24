#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
struct node *insert_after_node(struct node *head, struct node *n3, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next=n3->next;
    n3->next=new_node;
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    head->next = n1;
    n1->data = 1;
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    n1->next = n2;
    n2->data = 2;
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n2->next = n3;
    n3->data = 3;
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    n3->next = n4;
    n4->data = 4;
    struct node *n5 = (struct node *)malloc(sizeof(struct node));
    n4->next = n5;
    n5->data = 5;
    n5->next = NULL;
    // all data above
    printf("Linked list before insertion: \n");
    print(head);
    int data = 888;
    head = insert_after_node(head, n3, data);
    printf("Linked list after insertion: \n");
    print(head);
}