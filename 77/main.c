#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int GetNum(int n)
{
    int ret = 1;
    for (int i = 1; i < n; i++) {
        ret *= i;
    }
    return ret;
}

int GetAnsNum(int n, int m)
{
    return (GetNum(n) / (GetNum(n - m) * GetNum(m)));
}

int curRetPos = 0;
int curAnsPos = 0;
int Dfs(int n, int k, int cur, int **ans)
{
    // printf("%s %d %d %d\n", __func__, cur, curRetPos, curAnsPos);
    // if (cur + k > n) {
    //     printf("cur + k > n %s %d %d %d\n", __func__, cur, curRetPos, curAnsPos);
    //     return -1;
    // }
    if (curAnsPos == k) {
        printf("curAnsPos == k %s %d %d %d\n", __func__, cur, curRetPos, curAnsPos);
        curRetPos++;
        curAnsPos = 0;
        return 0;
    }
    printf("cur %d\n", cur);
    ans[curRetPos][curAnsPos] = cur;
    curAnsPos++;
    // int ret = Dfs(n, k, cur + 1, ans, curAnsPos + 1);
    // if (ret < 0) {
    //     return 0;
    // } else {

    // }
    for (int i = cur + 1; i <= n; i++) {
        Dfs(n, k, i, ans);
    }
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    curRetPos = 0;
    curAnsPos = 0;
    int ansNum = GetAnsNum(n, k);
    int **ret = malloc(sizeof(int *) * ansNum);
    *returnColumnSizes = malloc(sizeof(int) * ansNum);
    for (int i = 0; i < ansNum; i++) {
        ret[i] = malloc(sizeof(int) * k);
        memset(ret[i], 0, sizeof(int) * k);
        (*returnColumnSizes)[i] = k;

    }
    for (int i = 1; i <= n - k + 1; i++) {
        printf("111111\n");
        Dfs(n, k, i, ret);
    }
    *returnSize = ansNum;

    return ret;
}

int main()
{
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **ret = combine(4, 2, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        free(ret[i]);
        printf("\n");
    }
    free(ret);
    free(returnColumnSizes);

    ret = combine(1, 1, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        free(ret[i]);
        printf("\n");
    }
    free(ret);
    free(returnColumnSizes);
}
