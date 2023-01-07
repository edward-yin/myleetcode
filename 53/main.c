#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a:b;
}

int maxSubArray(int* nums, int numsSize){
    int res = 0, i = 0, pre = 0;
    int *resa = (int *)malloc(sizeof(int) * numsSize);

    resa[0] = nums[0];
    res = nums[0];
    for (i = 0; i < numsSize; i++) {
        pre = max(pre + nums[i], nums[i]);
        res = max(res, pre);

        printf("[%d] %d\n", i, res);
    }

    // for (i = 0; i < numsSize; i++) {
    //     res = max(resa[i], res);
    //     printf("resa[%d] %d\n", i, resa[i]);
    // }

    return res;

}


int main() {

    int res = 0, i = 0;

    {
        int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
        int numslen = 9;

        res = maxSubArray(nums, numslen);
        printf("res = %d\n", res);
    
    }

    {
        int nums[] = {5,4,-1,7,8};
        int numslen = 5;

        res = maxSubArray(nums, numslen);
        printf("res = %d\n", res);
    
    }





}