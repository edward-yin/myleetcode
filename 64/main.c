#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GRID_SIZE 200
int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    if (gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    int dp[MAX_GRID_SIZE][MAX_GRID_SIZE] = {{0}};
    int tmp = 0;
    for (int i = 0; i < gridSize; i++) {
        dp[i][0] = tmp + grid[i][0];
        tmp = dp[i][0];
    }
    tmp = 0;
    for (int i = 0; i < gridColSize[0]; i++) {
        dp[0][i] = tmp + grid[0][i];
        tmp = dp[0][i];
    }

    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[0]; j++) {
            dp[i][j] = grid[i][j] + fmin(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[gridSize - 1][gridColSize[0] - 1];
}

int main()
{
}
