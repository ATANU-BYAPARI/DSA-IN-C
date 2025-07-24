#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
void Traversal(struct NODE* ptr){
while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
}
}
int main()
{
    // CREATING 3 NODES
    struct NODE *head;
    struct NODE *second;
    struct NODE *third;
    // DYNAMICALLY ALLOCATING MEMORY IN HEAP
    head = (struct NODE*) malloc(sizeof(struct NODE)); // (data type) malloc(sizeof(data type))
    second = (struct NODE*) malloc(sizeof(struct NODE));
    third = (struct NODE*) malloc(sizeof(struct NODE));

    // we can directly write as following
    // struct NODE *head=(struct NODE*)malloc(sizeof(struct NODE));
    // ADDING DATA AND POINTING TO SECOND
    head->data = 5;
    head->next = second;
    // ADDING DATA AND POINTING TO THIRD
    second->data = 11;
    second->next = third;
    // ADDING DATA AND ENDING THE LINKED LIST
    third->data = 3;
    third->next = NULL;
    // CALLING THE TRAVERSAL FUNCTION
    Traversal(head);
}