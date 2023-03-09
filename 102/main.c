#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode *list[2000] = {0};
    int start = 0, end = 0;
    int **ret = (int **)malloc(sizeof(int*) * 2000);
    int *retSize = (int *)malloc(sizeof(int) * 2000);
    memset(ret, 0, 2000);
    memset(retSize, 0, 2000);
    
    struct TreeNode *p = NULL;
    list[end++] = root;
    int level = 0;
    while (start < end) {
        int levelSize = end - start;
        int levelStart = start;
        int levelEnd = end;
        ret[level] = (int *)malloc(sizeof(int) * levelSize);
        memset(ret[level], 0, sizeof(int) * levelSize);
        retSize[level] = levelSize;
        int j = 0;
        for (int i = levelStart; i < levelEnd; i++) {
            p = list[start++]; // pop
            if (p == NULL) {
                break;
            }
            if (p->left) {
                list[end++] = p->left;
            }
            if (p->right) {
                list[end++] = p->right;
            }
            ret[level][j++] = p->val;
            // if (level < 19) {
            //     continue;
            // }
            // printf("%d start %d end %d level %d levelSize %d\n", p->val, start, end, level, levelSize);
        }
        level++;
    }
    *returnColumnSizes = retSize;
    *returnSize = level;
    return ret;
}

int main()
{

}
