#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create_node()
{
    struct node *node_x = NULL;
    struct node *temp = NULL;
    printf("How many data to be inserted? ");
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid data\n");
        return NULL;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("Enter data of node %d\n", i);
        int data;
        scanf("%d", &data);
        if (i == 1)
        {
            struct node *head = (struct node *)malloc(sizeof(struct node));
            head->data = data;
            head->next = NULL;
            node_x = head;
            temp = head;
        }
        else
        {
            struct node *head = (struct node *)malloc(sizeof(struct node));
            head->data = data;
            head->next = NULL;
            temp->next = head;
            temp = head;
        }
    }
    printf("Linked list has been created successfully!\n");
    return node_x;
}
void print_node(struct node *ll1)
{
    struct node *ptr = ll1;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int length(struct node *node)
{
    struct node *ptr = node;
    int count = 0;
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}
void compare(struct node *ll1, struct node *ll2)
{
    struct node *ptr1 = ll1;
    struct node *ptr2 = ll2;
    if (length(ll1) != length(ll2))
    {
        printf("The lists are not identical!\n");
        return;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            printf("The linked lists are not identical!\n");
            return;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    printf("The linked lists are identical!\n");
    return;
}
void intersection(struct node *ll1, struct node *ll2)
{
    bool x=false;
    struct node *ptr1 = ll1;
    struct node *ptr2 = ll2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            printf("The intersection point data is: %d\n", ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            x=true;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
if(x==false){
    printf("No intersection point found!\n");
}
    return;
}
int main()
{
    struct node *ll1 = NULL; // list 1
    ll1 = create_node();
    struct node *ll2 = NULL; // list 2
    ll2 = create_node();

    compare(ll1, ll2);      // to compare similarity between list 1 and list 2
    intersection(ll1, ll2); // In linked list theory, intersection does not mean “same data values.” It means the two lists share actual nodes in memory (i.e., from some node onward, both lists point to the same memory addresses).
}