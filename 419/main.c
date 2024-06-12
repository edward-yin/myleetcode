#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int countBattleships(char** board, int boardSize, int* boardColSize)
{
    int totalNUm = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            // printf("i %d j %d x %c", i, j, board[i][j]);
            if (board[i][j] == 'X') {
                if (i > 0 &&  board[i - 1][j] == 'X') {
                    // xia
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
                totalNUm++;
            }
            // printf("totalNUm %d\n", totalNUm);
        }
    }
    return totalNUm;
}

int main()
{

}
