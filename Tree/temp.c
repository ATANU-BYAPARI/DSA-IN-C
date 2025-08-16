// balance factor = height of left subtree - height of right subtree
// bf can be -1 0 or 1 only
// ll rotation
// rr rotation
// lr rotation
// rl rotation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node; // duplicate keys not allowed
    }

    // Update height of current node
    node->height = 1 + max(getheight(node->left), getheight(node->right));

    // Get balance factor
    int bf = getbalancefactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

void preorder_traversal(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->key);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void inorder_traversal(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder_traversal(node->left);
    printf("%d ", node->key);
    inorder_traversal(node->right);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    printf("Preorder: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
