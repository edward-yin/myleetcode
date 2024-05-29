#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int pre = 0;
bool middle(struct TreeNode* root) {
    bool ret = false;
    if (!root) {
        return true;
    }
    ret = middle(root->left);
    if (ret == false) {
        return ret;
    }

    if (root->val <= pre) {
        return false;
    }
    ret = middle(root->right);
    pre = root->val;
    return ret;
}

bool isValidBST(struct TreeNode* root){
    middle(root);
}


int main {

}