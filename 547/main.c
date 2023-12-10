#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void Dfs(int** isConnected, int isConnectedSize, int row)
{
    if (row >= isConnectedSize || row < 0) {
        return;
    }
    if (isConnected[row][row] == 0) {
        return;
    }
    isConnected[row][row] = 0;
    // for (int i = row + 1; i < isConnectedSize; i++) {
    for (int i = 0; i < isConnectedSize; i++) {
        if (isConnected[row][i] == 1) {
            printf("%s i %d\n", __func__, i);
            Dfs(isConnected, isConnectedSize, i);
        }
    }
    return;
    // int size = 0;
    // if (isConnected[row][col] == 1) {
    //     size = 1;
    //     isConnected[row][col] = 0;
    //     size += Dfs(isConnected, isConnectedSize, row + 1);
    //     size += Dfs(isConnected, isConnectedSize, row - 1);
    //     size += Dfs(isConnected, isConnectedSize, row);
    //     size += Dfs(isConnected, isConnectedSize, row);
    // }
    // return size;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
    int ret = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (isConnected[i][i] == 1) {
            Dfs(isConnected, isConnectedSize, i);
            printf("i %d\n", i);
            ret++;
        }

    }
    return ret;
}

int main()
{
    int test1[3][3] = {{1,1,0},
                       {1,1,0},
                       {0,0,1}};
    int test1Size[3] = {0};
    int **p = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
        p[i] = malloc(sizeof(int) * 3);
        memcpy(p[i], test1[i], sizeof(int) * 3);
        test1Size[i] = 3;
    }
    int ret = findCircleNum(p, 3, test1Size);
    printf("ret %d\n", ret);
    

    
    int test2[4][4] = {{1,0,0,1},
                       {0,1,1,0},
                       {0,1,1,1},
                       {1,0,1,1}};
    int test2Size[4] = {0};
    int **p2 = malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++) {
        p2[i] = malloc(sizeof(int) * 4);
        memcpy(p2[i], test2[i], sizeof(int) * 4);
        test2Size[i] = 4;
    }
    ret = findCircleNum(p2, 4, test2Size);
    printf("ret %d\n", ret);
}
