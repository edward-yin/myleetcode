#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>

#define MAX_NUM 20001
int candy(int* ratings, int ratingsSize){
    int getCandy[MAX_NUM] = {0};
    for (int i = 0; i < ratingsSize - 1; i++) {
        if (ratings[i] < ratings[i + 1]) {
            getCandy[i + 1] = getCandy[i] + 1;
        }
    }

    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && getCandy[i] <= getCandy[i + 1]) {
            getCandy[i] = getCandy[i + 1] + 1;
        }
    }
    
    int ret = 0;
    for (int i = 0; i < ratingsSize; i++) {
        ret += getCandy[i];
    }
    ret += ratingsSize;
    return ret;
}

int main()
{

}
