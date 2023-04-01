#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 20001
bool IsLeftEmpty(int* flowerbed, int flowerbedSize, int i) {
    if (i == 0) {
        return true;
    }
    if (flowerbed[i - 1] == 0) {
        return true;
    }
    return false;
}

bool IsRightEmpty(int* flowerbed, int flowerbedSize, int i) {
    if (i == flowerbedSize - 1) {
        return true;
    }
    if (flowerbed[i + 1] == 0) {
        return true;
    }
    return false;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int planted = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            if (IsLeftEmpty(flowerbed, flowerbedSize, i) &&
                IsRightEmpty(flowerbed, flowerbedSize, i)) {
                planted++;
                flowerbed[i] = 1;
            }
        }
    }
    return (planted >= n);
}
int main()
{

}
