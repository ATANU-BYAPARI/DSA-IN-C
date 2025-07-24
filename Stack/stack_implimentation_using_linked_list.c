#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void print(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("data: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int pop(struct node** head){
    struct node* ptr=*head;
    if(ptr!=NULL){
        int x=(ptr)->data;
        *head=ptr->next;
        free(ptr);
        return x;
    }
}
struct node* push(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
int main(){
    struct node* head=NULL; // creates a empty list
    head=push(head,5);
    head=push(head,6);
    head=push(head,7);
    head=push(head,8);
    head=push(head,9);
    head=push(head,10);
    print(head);
    pop(&head);
    pop(&head);
    pop(&head);
}