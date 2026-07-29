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

void preorder(struct node* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
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

void postorder(struct node* root) 
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    int n, x;
    scanf("%d", &n);
    struct node* root = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
