#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool Dfs(char** board, int boardSize, int boardColSize, char *word, int n, int curRow, int curCol)
{
    if (strlen(word) == n) {
        return true;
    }
    if (curRow >= boardSize || curRow < 0 || curCol < 0 || curCol >= boardColSize) {
        return false;
    }
    bool ret = Dfs(board, boardSize, boardColSize, word, n + 1, curRow + 1, curCol);
    if (ret == true) {
        return ret;
    }
    ret = Dfs(board, boardSize, boardColSize, word, n + 1, curRow - 1, curCol);
    if (ret == true) {
        return ret;
    }
    ret = Dfs(board, boardSize, boardColSize, word, n + 1, curRow, curCol + 1);
    if (ret == true) {
        return ret;
    }
    ret = Dfs(board, boardSize, boardColSize, word, n + 1, curRow, curCol - 1);
    return ret;

}

bool exist(char** board, int boardSize, int* boardColSize, char *word)
{
    bool ret = false;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == word[0]) {
                ret = Dfs(board, boardSize, boardColSize[0], word, 0, i, j);
            }
        }
    }
    return ret;
}

int main()
{
    char *test1 = "ABCCED";
    char *board[] = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    int colSize[3] = {4,4,4};
    bool ret = exist(board, 3, colSize, test1);
    printf("ret %d\n", ret);
}
