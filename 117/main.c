#include <stdio.h>
#include <stdring.h>
#include <stdlib.h>





struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *find_next(struct Node *root) {
    while (root) {
        if (root->left)
            return root->left;
        if (root->right)
            return root->right;
        root = root->next;
    }
    return NULL;
}

struct Node* connect(struct Node* root) {
    if (!root)
        return NULL;
    if (root->right)
        root->right->next = find_next(root->next);
    if (root->left)
        root->left->next = root->right ? root->right : find_next(root->next);
      
    connect(root->right);
    connect(root->left);
    return root;
}
