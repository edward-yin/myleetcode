#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int comp(const void *a, const void *b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;

    return (b1 - a1);
}

int maxCoins(int* piles, int pilesSize)
{
    int ret = 0;

    qsort(piles, pilesSize, sizeof(piles[0]), comp);
    int takeNum = (pilesSize * 2)/3;

    for (int i = 1; i < takeNum; i += 2) {
        ret += piles[i];
    }
    return ret;
}

int main()
{
    {
    int piles[] = {2,4,1,2,7,8};
    int ret = maxCoins(piles, 6);
    printf("ret = %d\n", ret);
    }
    {
    int piles[] = {2,4,5};
    int ret = maxCoins(piles, 3);
    printf("ret = %d\n", ret);
    }
    {
    int piles[] = {9,8,7,6,5,1,2,3,4};
    int ret = maxCoins(piles, 9);
    printf("ret = %d\n", ret);
    }

}
