#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    struct node *left;
    struct node *right;
    int data;
};
int check(int x, int *y)
{
    if (x > *y)
    {
        *y = x;
        return 1;
    }
    else
    {
        return 0;
    }
}
int inorder_traversal(struct node *ptr, int *y)
{
    if (ptr != NULL)
    {
        inorder_traversal(ptr->left, y);
        if (check(ptr->data, y) == 0)
        {
            return 0;
        }
        else
        {
            return inorder_traversal(ptr->right, y);
        }
    }
    else
    {
        return 1;
    }
}
int isBST(struct node *ptr)
{
    int y = INT_MIN;
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return inorder_traversal(ptr, &y);
    }
}
int main()
{
    // create node and update its data field
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    // struct node *node5 = (struct node *)malloc(sizeof(struct node));
    node0->data = 5;
    node1->data = 3;
    node2->data = 7;
    node3->data = 6;
    node4->data = 4;
    // node5->data = 1;

    node0->left = node1;
    node1->left = node3;
    node0->right = node2;
    node1->right = node4;
    // node3->left = node5;
    node3->left=NULL;
    node3->right = NULL;
    node4->left = node4->right = NULL;
    node2->left = node2->right = NULL;
    // node5->left = node5->right = NULL;
    int valid = isBST(node0);
    if (valid == 1)
    {
        printf("The tree is a Binary Search Tree\n"); // we can aslo check it by doing, 1. find inorder traversal, 2. then find the output is sorted or not
    }
    else
    {
        printf("The tree is not a Binary Search Tree\n");
    }
    free(node0);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    // free(node5);
    return 0;
}