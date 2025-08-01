#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *insertion_bst(struct node *root, int key)
{
    if (root->left == NULL || root->right == NULL)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = key;
        new_node->left = NULL;
        new_node->right = NULL;
        if (root->left == NULL && key < root->data)
        {
            root->left = new_node;
            return root->left;
        }
        else if (root->right == NULL && key > root->data)
        {
            root->right = new_node;
            return root->right;
        }
        else
        {
            printf("The data %d can't be inserted!\n", key);
            free(new_node);
        }
        return root;
    }
    else if (key > root->data)
    {
        return insertion_bst(root->right, key);
    }
    else if (key < root->data)
    {
        return insertion_bst(root->left, key);
    }
    else
    {
        printf("The data %d can't be inserted!\n", key);
        return NULL;
    }
}
void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
    return;
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
    int key = 45;
    insertion_bst(root, key);      // insert 45
    insertion_bst(root, key + 10); // insert 55
    insertion_bst(root, key + 20); // insert 65
    inorder_traversal(root);
    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    return 0;
}