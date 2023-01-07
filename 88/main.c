#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
   int i = m--+--n;
        
    // while(n>=0) {
    //     nums1[i--] = m>=0 && nums1[m]>nums2[n] ? nums1[m--] : nums2[n--];
    // }
    
    while (n >= 0) {

        if ((m >= 0) && (nums1[m] > nums2[n])) {
            nums1[i--] = nums1[m];
            m--;
        } else {
            nums1[i--] = nums2[n];
            n--;
        }
        
    }

}


int main () {


    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    int n1 = 6, i = 0;

    merge(nums1, 6, 3, nums2, 3, 3);
    for(i = 0; i < n1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

}