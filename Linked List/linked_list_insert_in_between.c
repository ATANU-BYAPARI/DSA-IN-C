#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insert_in_between(int data,int pointer_index,struct node* head){
    struct node* insert=(struct node*)malloc(sizeof(struct node));
    insert->data=data;
    struct node* p=head; // coping head node
    int i=0;
    while(i<pointer_index-1){
        p=p->next;
        i++;
    }
    insert->next=p->next;
    p->next=insert;
}
void print_linked_list(struct node* head){
    struct node* ptr=head;
while(ptr->next!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
}
}
int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    struct node* fifth=(struct node*)malloc(sizeof(struct node));

    // setting data to all
    head->data=50;
    second->data=51;
    third->data=52;
    fourth->data=53;
    fifth->data=54;
    
    // setting pointer
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    // function calling
    int data=59;
    int pointer_index=3;
    insert_in_between(data,pointer_index,head);

    // print linked list
    print_linked_list(head);
}