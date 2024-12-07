#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
int MyMin(int a, int b, int c)
{
    int min = fmin(a, b);
    min = fmin(min, c);
    return min;
}
int minFallingPathSum(int **matrix, int matrixSize, int *matrixColSize)
{
    int dp[MAX_SIZE][MAX_SIZE] = {{0}};
    for (int i = 0; i < matrixSize; i++)
    {
        dp[0][i] = matrix[0][i];
        /* code */
    }
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            dp[i][j] = matrix[i][j];
            if (j == 0) {
                dp[i][j] += fmin(matrix[i - 1][j], matrix[i - 1][j + 1]);
                continue;
            }
            if (j == matrixColSize[0] - 1) {
                dp[i][j] += fmin(matrix[i - 1][j - 1], matrix[i - 1][j]);
                continue;
            }
            dp[i][j] += MyMin(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]);
        }
    }
    int min = 500;
    for (int i = 0; i < matrixColSize[0]; i++) {
        min = fmin(min, dp[matrixSize - 1][i]);
    }
    return min;    
}

int main()
{
}
