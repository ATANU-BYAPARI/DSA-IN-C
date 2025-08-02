#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
void create_node(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return;
}
int main(){
    create_node(0);
    create_node(1);
    create_node(2);
    create_node(3);
    create_node(4);
    create_node(5);
    return 0;
}