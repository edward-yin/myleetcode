#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int) * 2);
    if (ret == NULL) {
        return NULL;
    }

    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    if (numsSize == 0) {
        return ret;
    }

    // left
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == target) {
            ret[0] = i;
            ret[1] = i;
        }
    }

        // left
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            ret[1] = i;
        }
    }
    return ret;
}

int main()
{

    int test1[6] = {5,7,7,8,8,10};
    int retSize = 0;
    int *ret = searchRange(test1, 6, 8, &retSize);
    if (ret != NULL) {
        printf("%d, %d\n", ret[0], ret[1]);
        free(ret);
        ret = NULL;
    }
    ret = searchRange(test1, 6, 6, &retSize);
    if (ret != NULL) {
        printf("%d, %d\n", ret[0], ret[1]);
        free(ret);
        ret = NULL;
    }
    ret = searchRange(NULL, 0, 0, &retSize);
    if (ret != NULL) {
        printf("%d, %d\n", ret[0], ret[1]);
        free(ret);
        ret = NULL;
    }
}
