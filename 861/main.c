#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int matrixScore(int **grid, int gridSize, int* gridColSize)
{
    int m = gridSize, n = gridColSize[0];

    int ret = m * (1 << (n - 1));

    int ones = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[j][0] == 0) {
                // 翻转过
                ones += (1 - grid[j][i]);
            } else {
                ones += grid[j][i];
            }
        }
        ones = max(ones, m - ones);
        ret += ones * (1 << (n - i - 1));
        ones = 0;
    }
    return ret;
}

int main()
{
    int grid1[3][4] = {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };

    int **grid = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
        grid[i] = (int *)malloc(sizeof(int) * 4);
        memcpy(grid[i], grid1[i], sizeof(int) * 4);
    }
    int size[3] = {4,4,4};
    int ret = matrixScore(grid, 3, size);
    printf("%d\n", ret);

}
