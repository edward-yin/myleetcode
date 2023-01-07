#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int maxIncreaseKeepingSkyline(int grid[][4], int gridSize, int* gridColSize)
{
    int *maxCol = malloc(sizeof(int) * gridSize);
    int *maxRow = malloc(sizeof(int) * gridSize);

    memset(maxCol, 0, sizeof(int) * gridSize);
    memset(maxRow, 0, sizeof(int) * gridSize);

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            maxRow[i] = max(maxRow[i], grid[i][j]);
        }
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            maxCol[i] = max(maxCol[i], grid[j][i]);
        }
    }

    for (int i = 0; i < gridSize; i++) {
        printf("row %d, col %d\n", maxRow[i], maxCol[i]);
    }

    int ret = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            ret += min(maxRow[i], maxCol[j]) - grid[i][j];
        }
    }

    return ret;
}

int main()
{
    int grid[4][4] = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    int gridSize = 4;
    int gridColSize[4] = {4, 4, 4, 4};

    int ret = maxIncreaseKeepingSkyline(grid, gridSize, gridColSize);
    printf("ret = %d\n", ret);
    return 0;
}

    // int gridSize = 4;
    // int **grid = malloc(sizeof(int*) * gridSize);
    // int gridColSize[4] = {4, 4, 4, 4};

    // for (int i = 0 ; i < gridSize; i++) {
    //     grid[i] = malloc(sizeof(int) * gridSize);
        
    // }