#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GRID_SIZE 100
int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{


    if (obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGridSize - 1][obstacleGridColSize[0] - 1] == 1) {
        return 0;
    }
    if (obstacleGridSize == 1 || obstacleGridColSize[0] == 1) {
        return 1;
    }

    int dp[MAX_GRID_SIZE][MAX_GRID_SIZE] = {{0}};
    for (int i = 0; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 1) {
            dp[i][0] = 0;
            break;
        } else {
            dp[i][0] = 1;
        }
    }
    for (int i = 0; i < obstacleGridColSize[0]; i++) {
        if (obstacleGrid[0][i] == 1) {
            dp[0][i] = 0;
            break;
        } else {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < obstacleGridSize; i++) {
        for (int j = 1; j < obstacleGridColSize[0]; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}

int main()
{
}
