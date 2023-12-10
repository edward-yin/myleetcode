#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <uthash.h>
typedef struct {
    int sum;
    int num;
    UT_hash_handle hh;
}MyHash;
int subarraySum(int* nums, int numsSize, int k){
    int cnt = 0;
    int left = 0, right = 0;
    MyHash *hash = NULL;
    MyHash *t = NULL;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        HASH_FIND_INT(hash, &sum, t);
        if (t == NULL) {
            t = malloc(sizeof(MyHash));
            t->num = 0;
            t->sum = sum;
            HASH_ADD_INT(hash, sum, t);
        }
        t->num++;
    }
    
    MyHash *p = NULL, *tmp = NULL;
    int key = 0;
    HASH_ITER(hh, hash, t, p) {
        key = t->sum - 2;
        HASH_FIND_INT(hash, &key, tmp);
        if (tmp != NULL) {
            cnt += tmp->num;
        }
    }
    return cnt;
}
int main()
{

}
