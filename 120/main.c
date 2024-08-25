#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 200
int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    int dp[MAX_SIZE][MAX_SIZE] = {{55555}};
    for (int i = 0; i < MAX_SIZE; i++) {
        memset(dp[i], 55555, sizeof(int) * MAX_SIZE);
    }
    int tmp = 0;
    for (int i = 0; i < triangleSize; i++) {
        dp[i][0] = tmp + triangle[i][0];
        tmp = dp[i][0];
        if (i == 0) {
            continue;
        }
        dp[i][triangleColSize[i] - 1] = dp[i - 1][triangleColSize[i] - 2] + triangle[i][triangleColSize[i] - 1];
    }

    for (int i = 2; i < triangleSize; i++) {
        for (int j = 1; j < triangleColSize[i]; j++) {
            dp[i][j] = fmin(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
    }
    int min = 55555;
    for (int j = 0; j < triangleColSize[triangleSize - 1]; j++) {
        min = fmin(min, dp[triangleSize - 1][j]);
    }
    return min;
}

int main()
{
}
