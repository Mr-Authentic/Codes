#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int val) 
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int val) 
{
    if (root == NULL) 
        return newNode(val);
    if (val < root->data) 
        root->left = insert(root->left, val);
    else if (val > root->data) 
        root->right = insert(root->right, val);
    return root;
}

struct node* minValueNode(struct node* root) 
{
    struct node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key) 
{
    if (root == NULL) return root;

    if (key < root->data) 
        root->left = deleteNode(root->left, key);
    else if (key > root->data) 
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() 
{
    int n, x, key;
    scanf("%d", &n);
    struct node* root = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d", &key);
    root = deleteNode(root, key);
    inorder(root);
    return 0;
}
