#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *search_bst(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search_bst(root->left, key);
    }
    else if (root->data < key)
    {
        return search_bst(root->right, key);
    }
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 60;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 40;
    root->left = node1;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 80;
    root->right = node2;
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 30;
    node1->left = node3;
    node3->left = NULL;
    node3->right = NULL;
    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    node4->data = 50;
    node4->left = NULL;
    node4->right = NULL;
    node1->right = node4;
    struct node *node5 = (struct node *)malloc(sizeof(struct node));
    node5->left = NULL;
    node5->right = NULL;
    node5->data = 70;
    node2->left = node5;
    struct node *node6 = (struct node *)malloc(sizeof(struct node));
    node6->left = NULL;
    node6->right = NULL;
    node6->data = 90;
    node2->right = node6;
    int key = 0;
    if (search_bst(root, key) != NULL)
    {
        printf("Key %d found!\n", key);
    }
    else
    {
        printf("Key %d not found!\n", key);
    }
    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    return 0;
}