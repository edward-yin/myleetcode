#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void middle(struct TreeNode* root, int *ret, int *returnSize) {
    if (!root) {
        return;
    }

    middle(root->left, ret, returnSize);
    ret[*returnSize] = root->val;
    (*returnSize)++;
    middle(root->right, ret, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = (int *)malloc(sizeof(int *)*101);
    *returnSize = 0;

    middle(root, ret, returnSize);

    return ret;
}


