#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int singleNonDuplicate(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize - 1; i += 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}

int main()
{
    int test1[9] = {1,1,2,3,3,4,4,8,8};
    int ret = singleNonDuplicate(test1, 9);
    printf("%d\n", ret);

    int test2[7] = {3,3,7,7,10,11,11};
    ret = singleNonDuplicate(test2, 7);
    printf("%d\n", ret);
}
