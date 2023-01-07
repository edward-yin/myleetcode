#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char nums[9][9] = {{5,3,'.','.',7,'.','.','.','.'},
                   {6,'.','.',1,9,5,'.','.','.'},
                   {'.',9,8,'.','.','.','.',6,'.'},
                   {8,'.','.','.',6,'.','.','.',3},
                   {4,'.','.',8,'.',3,'.','.',1},
                   {7,'.','.','.',2,'.','.','.',6},
                   {'.',6,'.','.','.','.',2,8,'.'},
                   {'.','.','.',4,1,9,'.','.',5},
                   {'.','.','.','.',8,'.','.',7,9}};

int numssize[9] = {9,9,9,9,9,9,9,9,9};

 int isValidSudoku(char** board, int boardSize, int* boardColSize){

    int i = 0, j = 0;
    int k = 0, l = 0;
    int smallr, smallc;
    char tmp;
    
    for (i = 0; i < boardSize; i++) {
        
        for (j = 0;j < boardColSize[i]; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            tmp = board[i][j];
            for (k = j + 1; k < boardColSize[i]; k++) {
                if (tmp == board[i][k]) {
                    return 0;
                }
            }
            
            for (l = i + 1; l < boardSize; l++) {
                if (tmp == board[l][j]) {
                    return 0;
                }
            }
            smallr = i/3*3;
            smallc = j/3*3;
            for (k = i/3; k < smallr; k++) {
                for (l = j/3; l < smallc; l++) {
                    if (tmp == board[k][l]) {
                        return 0;
                    }
                    
                }
            }
        }
    }
    
    return 1;
}


int main() {

    int ret = 0;

    ret = isValidSudoku(nums, 9, numssize);

    printf("%d\n", ret);
}