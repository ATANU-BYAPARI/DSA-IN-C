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
    node0->data = 5;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 3;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 6;
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 1;
    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    node4->data = 4;

    // pointing left and right pointers with other nodes
    node0->left = node1;
    node0->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node2->right = NULL;
    node3->left = node3->right = NULL;
    node4->left = node4->right = NULL;
    // the tree will look like (below...)
    //        n0
    //      /   \
    //    n1     n2
    //   / \
    // n3  n4
    void inorder_traversal(struct node *); //function prototype declaration
    inorder_traversal(node0);
    return 0;
}
void inorder_traversal(struct node *node0)
{
    if (node0!= NULL)
    {
    inorder_traversal(node0->left);
    printf("%d ", node0->data);
    inorder_traversal(node0->right);
    } // prints 1 3 4 5 6, property of BST, inorder traversal gives ascending order sorted numbers
    //press F2 for rename
    return;
}