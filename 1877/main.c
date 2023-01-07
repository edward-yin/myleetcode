#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(int *a, int *b)
{
    return *a - *b;
}

int minPairSum(int* nums, int numsSize)
{
    if (numsSize == 2) {
        return nums[0] + nums[1];
    }
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    int *sums = (int *)malloc((numsSize/2) * sizeof(int));
    memset(sums, 0, (numsSize/2) * sizeof(int));
    int max = 0;
    for (int i = 0; i < numsSize/2; i++) {
        // max = fmax(max, nums[i] + nums[numsSize - 1 - i]);
    }

    return max;
}

int main()
{
    int ret = 0;
    {
        int nums[] = {3,5,2,3};
        ret = minPairSum(nums, 4);
        printf("ret = %d\n", ret);
    }
    {
        int nums[] = {3,5,4,2,4,6};
        ret = minPairSum(nums, 6);
        printf("ret = %d\n", ret);
    }
    {
        int nums[4] = {3,5,2,3};
        ret = minPairSum(nums, 4);
        printf("ret = %d\n", ret);
    }

}
