#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool MidSearch(int *nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r + 1) / 2;
        if (mid == l || mid == r) {
            return false;
        }
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            r = mid;
        } else {
            l = mid;
        }
        printf("l %d, r %d, mid %d\n", l, r, mid);
    }
    return false;
}

bool search(int* nums, int numsSize, int target)
{
    int reverse = 0;
    for (reverse = 0; reverse < numsSize - 1; reverse++) {
        if (nums[reverse] > nums[reverse + 1]) {
            break;
        }
    }

    if (target == nums[reverse]) {
        return true;
    } else {
        bool ret = MidSearch(nums, reverse, target);
        printf("ret1 %d\n", ret);
        ret |= MidSearch(nums + reverse, numsSize - reverse, target);
        printf("ret2 %d\n", ret);
        return ret;
    }
    return false;
}

int main()
{
    int test1[7] = {2,5,6,0,0,1,2};
    bool ret = search(test1, 7, 0);
    printf("%d\n", ret);

    ret = search(test1, 7, 3);
    printf("%d\n", ret);
    int test2[2] = {1,3};
    ret = search(test2, 2, 1);
    printf("%d\n", ret);
}
