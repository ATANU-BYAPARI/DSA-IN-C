#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void print_(struct node* ptr){
while(ptr!=NULL){
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
// insert at beginning
int main(){
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* second=(struct node*)malloc(sizeof(struct node));
struct node* third=(struct node*)malloc(sizeof(struct node));
head->data=5;
second->data=6;
third->data=7;

head->next=second;
second->next=third;
third->next=NULL;

struct node* new=(struct node*)malloc(sizeof(struct node));
new->data=4;
new->next=head;
head=new;
print_(head);
}