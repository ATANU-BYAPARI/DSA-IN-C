#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *ipe_traversal(struct node *root)
{
    struct node *prev = root;
    if(root->left != NULL){
        root = root->left;
        while(root->right != NULL){
            prev = root;
            root = root->right;
        }
        return root;
    }
    if(root->right != NULL){
        root = root->right;
        while(root->left != NULL){
            prev = root;
            root = root->left;
        }
        return root;
    }
    return NULL;
}
struct node *deletion_bst(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Key %d not found!\n", key);
        return NULL;
    }
    if (key == root->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            printf("Key %d deleted!\n", key);
            free(root);
            return NULL;
        }
        else
        {
            struct node *temp = ipe_traversal(root);
            if (temp != NULL)
            {
                int tempData = temp->data;
                root = deletion_bst(root, temp->data); // delete that ipe/successor
                root->data = tempData;
                return root;
            }
        }
        return root;
    }
    else if (key > root->data)
    {
        root->right = deletion_bst(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deletion_bst(root->left, key);
    }
    return root;
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
    int key = 70;
    deletion_bst(root, key - 30);      // delete 40
    deletion_bst(root, key + 10);      // delete 80 or 90 depending on key
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
