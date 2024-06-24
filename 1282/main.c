#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "uthash.h"

typedef struct {
    int index;
    int groupSize;
    UT_hash_handle hh;
}MyGroup;

int GroupCmp(MyGroup *a, MyGroup *b)
{
    return a->groupSize - b->groupSize;
}

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes)
{
    MyGroup *group = NULL;
    MyGroup *member = NULL;
    for (int i = 0; i < groupSizesSize; i++) {
        member = malloc(sizeof(MyGroup));
        if (member == NULL) {
            return NULL;
        }
        member->index = i;
        member->groupSize = groupSizes[i];
        HASH_ADD(hh, group, index, sizeof(int), member);
    }
    HASH_SORT(group, GroupCmp);

    MyGroup *el = NULL, *tmp = NULL;
    int **ret = malloc(sizeof(int *) * groupSizesSize);
    int *returnColSizes = malloc(sizeof(int) * groupSizesSize);
    int nowSize = 0;
    int groupIndex = 0;
    HASH_ITER(hh, group, el, tmp) {
        if (el == NULL) {
            continue;
        }
        if (ret[groupIndex] == NULL) {
            ret[groupIndex] = malloc(sizeof(int) * el->groupSize);
        }
        ret[groupIndex][nowSize++] = el->index;
        if (nowSize == el->groupSize) {
            returnColSizes[groupIndex] = el->groupSize;
            groupIndex++;
            nowSize = 0;
        }
    }
    *returnColumnSizes = returnColSizes;
    *returnSize = groupIndex;
    return ret;
}

int main()
{
    int input[7] = {3,3,3,3,3,1,3};
    int retSize = 0;
    int *returnColSize = NULL;
    int **outPut = groupThePeople(input, 7, &retSize, &returnColSize);
    for (int i = 0; i < retSize; i++) {
        printf("i %d, ");
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d, ", outPut[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
