#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int main()
{
    // node creation and updating their data fields
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 0;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 1;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 2;
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 3;

    // pointing left and right pointers with other nodes
    node0->left = node1;
    node0->right = node2;
    node1->left = node3;
    node1->right = NULL;
    node2->left = node2->right = NULL;
    node3->left = node3->right = NULL;
    // the tree will look like (below...)
    //        n0
    //      /   \
    //    n1     n2
    //   /
    // n3
}