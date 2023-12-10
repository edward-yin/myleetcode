#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int Dfs(int** grid, int gridSize, int gridColSize, int row, int col)
{
    if (row >= gridSize || row < 0 || col < 0 || col >= gridColSize) {
        return 0;
    }
    int size = 0;
    if (grid[row][col] == 1) {
        size = 1;
        grid[row][col] = 0;
        size += Dfs(grid, gridSize, gridColSize, row + 1, col);
        size += Dfs(grid, gridSize, gridColSize, row - 1, col);
        size += Dfs(grid, gridSize, gridColSize, row, col + 1);
        size += Dfs(grid, gridSize, gridColSize, row, col - 1);
    }
    return size;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int col = gridColSize[0];
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                ans = Max(ans, Dfs(grid, gridSize, col, i, j));
                printf("ans %d\n", ans);
            }
        }
    }
    return ans;

}

int main()
{
    int test1[8][13] = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,1,1,0,0,1,0,1,0,0},
                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int test1Size[8] = {0};
    int **p = malloc(sizeof(int *) * 8);
    for (int i = 0; i < 8; i++) {
        p[i] = malloc(sizeof(int) * 13);
        memcpy(p[i], test1[i], sizeof(int) * 13);
        test1Size[i] = 13;
    }
    int ret = maxAreaOfIsland(p, 8, test1Size);
    printf("ret %d\n", ret);
}
