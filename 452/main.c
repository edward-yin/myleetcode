#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CmpRange(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;

    if (a1[0] < b1[0]) {
        return 1;
    } else {
        return b1[1] - a1[1];
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    for (int i = 0; i < pointsSize; i++) {
        printf("%d, %d\n", points[i][0], points[i][1]);
    }
    printf("######\n");
    qsort(points, pointsSize, sizeof(int *) * 2, CmpRange);
    for (int i = 0; i < pointsSize; i++) {
        printf("%d, %d\n", points[i][0], points[i][1]);
    }
}

int test1[4][2] = {
    {10,16},{2,8},{1,6},{7,12}
};
int main()
{
    int **points = malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++) {
        points[i] = malloc(sizeof(int) * 2);
        points[i][0] = test1[i][0];
        points[i][1] = test1[i][1];
    }

    int ret = findMinArrowShots(points, 4, 0);
    return 0;
}
