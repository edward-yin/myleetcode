#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void CopyLeft(int *nums, int numSize, int dstOffset, int srcOffset)
{
    printf("dst %d src %d\n", dstOffset, srcOffset);
    // for (int i = srcOffset; i < numSize; i++) {
    //     nums[dstOffset + 1 + i] = nums[i];
    // }
    // memmove(nums + dstOffset * sizeof(int), nums + srcOffset * sizeof(int), (numSize - srcOffset) * sizeof(int));
}

int removeDuplicates(int *nums, int numsSize)
{
    int j = 0, dst = 0, src = 0;
    int last = nums[0];
    int numLen = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == last) {
            j++;
        } else {
            j = 0;
            last = nums[i];
        }
        if (j == 2) {
            // mark dst
            dst = i;
        }
        if (j == 0 && i != 0) {
            // copy
            src = i;
            CopyLeft(nums, numsSize, dst, src);
            i = dst + 1;
            numLen -= (src - dst);
        }
    }
    return numLen;
}

int main()
{
    int num[6] = {1,1,1,2,2,3};
    int *nums = malloc(sizeof(int) * 6);
    memcpy(nums, num, sizeof(int) * 6);
    removeDuplicates(nums, 6);
    
}
