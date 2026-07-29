#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    char color;
    struct Node *left, *right, *parent;
} Node;

Node *root = NULL;

Node* createNode(int data) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->color = 'R';
    n->left = n->right = n->parent = NULL;
    return n;
}

Node* bstInsert(Node *r, Node *pt) {
    if (!r) return pt;
    if (pt->data < r->data) {
        r->left = bstInsert(r->left, pt);
        r->left->parent = r;
    } else if (pt->data > r->data) {
        r->right = bstInsert(r->right, pt);
        r->right->parent = r;
    }
    return r;
}

void rotateLeft(Node **r, Node *pt) {
    Node *y = pt->right;
    pt->right = y->left;
    if (y->left) y->left->parent = pt;
    y->parent = pt->parent;
    if (!pt->parent) *r = y;
    else if (pt == pt->parent->left) pt->parent->left = y;
    else pt->parent->right = y;
    y->left = pt;
    pt->parent = y;
}

void rotateRight(Node **r, Node *pt) {
    Node *y = pt->left;
    pt->left = y->right;
    if (y->right) y->right->parent = pt;
    y->parent = pt->parent;
    if (!pt->parent) *r = y;
    else if (pt == pt->parent->left) pt->parent->left = y;
    else pt->parent->right = y;
    y->right = pt;
    pt->parent = y;
}

void fixViolation(Node **r, Node *pt) {
    if (pt == *r) { pt->color = 'B'; return; }
    if (pt->parent->color == 'B') { (*r)->color = 'B'; return; }

    Node *parent = pt->parent, *gparent = parent->parent, *uncle;

    if (parent == gparent->left) {
        uncle = gparent->right;
        if (uncle && uncle->color == 'R') {
            parent->color = 'B';
            uncle->color = 'B';
            gparent->color = 'R';
            fixViolation(r, gparent);
        } else {
            if (pt == parent->right) {
                rotateLeft(r, parent);
                pt = parent;
                parent = pt->parent;
            }
            rotateRight(r, gparent);
            char t = parent->color;
            parent->color = gparent->color;
            gparent->color = t;
        }
    } else {
        uncle = gparent->left;
        if (uncle && uncle->color == 'R') {
            parent->color = 'B';
            uncle->color = 'B';
            gparent->color = 'R';
            fixViolation(r, gparent);
        } else {
            if (pt == parent->left) {
                rotateRight(r, parent);
                pt = parent;
                parent = pt->parent;
            }
            rotateLeft(r, gparent);
            char t = parent->color;
            parent->color = gparent->color;
            gparent->color = t;
        }
    }

    (*r)->color = 'B';
}

void insert(int data) {
    Node *pt = createNode(data);
    root = bstInsert(root, pt);
    fixViolation(&root, pt);
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d(%c) ", r->data, r->color);
    inorder(r->right);
}

int main() {
    int x;
    printf("Enter numbers to insert (-1 to stop):\n");
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        insert(x);
    }
    printf("\nInorder Traversal:\n");
    inorder(root);
    return 0;
}
