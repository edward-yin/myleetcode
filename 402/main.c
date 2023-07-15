#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Comp1(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;

    return a1[0] == b1[0] ? a1[1] - b1[1] : b1[0] - a1[0];
}

void PrintArray(int **array, int size) {
    printf("#########start %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d %d\n", array[i][0], array[i][1]);
    }
    printf("#########end %d\n", size);
}

void InserRes(int** array, int arraySize, int *item, int index)
{
    if (arraySize >= index) {
        for (int i = arraySize; i >= index; i--) {
            array[i + 1][0] = array[i][0];
            array[i + 1][1] = array[i][1];
        }
    }

    array[index][0] = item[0];
    array[index][1] = item[1];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    int **ret = malloc(sizeof(int *) * peopleSize);
    if (ret == NULL) {
        return NULL;
    }
    *returnSize = peopleSize;
    int *colSize = malloc(sizeof(int) * peopleSize);
    if (colSize == NULL) {
        return NULL;
    }
    memset(colSize, 0, sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        ret[i] = malloc(peopleColSize[i] * sizeof(int));
        if (ret[i] == NULL) {
            return NULL;
        }
        memset(ret[i], 0, peopleColSize[i] * sizeof(int));
    }

    qsort(people, peopleSize, sizeof(int *), Comp1);

    for (int i = 0; i < peopleSize; i++) {
        InserRes(ret, i - 1, people[i], people[i][1]);
        colSize[i] = 2;
        PrintArray(ret, i + 1);
    }

    *returnColumnSizes = colSize;
    return ret;
}

int test1[][2] = {
    {7,0},{4,4},{7,1},{5,0},{6,1},{5,2}
};

int main()
{
    int *colSize = malloc(6 * sizeof(int));
    if (colSize == NULL) {
        return 0;
    }
    int **p = malloc(6 * sizeof(int *));
    if (p == NULL) {
        return 0;
    }
    for (int i = 0; i < 6; i++) {
        colSize[i] = 2;
        p[i] = malloc(2 * sizeof(int));
        if (p[i] == NULL) {
            return 0;
        }
        p[i][0] = test1[i][0];
        p[i][1] = test1[i][1];
    }


    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **ret = reconstructQueue(p, 6, colSize, &returnSize, &returnColumnSizes);
    free(colSize);
    if (ret == NULL) {
        printf("err.\n");
        return 0;
    }
    
    PrintArray(ret, returnSize);
    free(ret);
    free(returnColumnSizes);
}
