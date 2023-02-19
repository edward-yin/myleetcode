#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>

int max(int a, int b) {
    return a > b ? a : b;
}
int* partitionLabels(char * s, int* returnSize){
    int *ret = NULL;
    int retSize = 0;
    int c = 0;
    int start = 0, end = 0;
    size_t len = strlen(s);
    ret = (int *)malloc(len* sizeof(int));

    int i = 0;
    while (i < len) {
        c = s[i];
        start = strchr(s, c) - s;
        end = strrchr(s, c) - s;
        for (int j = start; j < end; j++) {
            end = max(end, (strrchr(s, s[j]) - s));
        }
        ret[retSize++] = end - start + 1;
        i = end + 1;
    }

    *returnSize = retSize;
    return ret;
}

int main()
{
    {
    char *s = "ababcbacadefegdehijhklij";
    int retSize = 0;
    int *ret = partitionLabels(s, &retSize);
    for (int i = 0; i < retSize; i++) {
        printf("%d ", ret[i]);
    }
    free(ret);
    printf("\n");
    }
    {
    char *s = "eccbbbbdec";
    int retSize = 0;
    int *ret = partitionLabels(s, &retSize);
    for (int i = 0; i < retSize; i++) {
        printf("%d ", ret[i]);
    }
    free(ret);
    printf("\n");
    }
    {
    char *s = "dccccbaabe";
    int retSize = 0;
    int *ret = partitionLabels(s, &retSize);
    for (int i = 0; i < retSize; i++) {
        printf("%d ", ret[i]);
    }
    free(ret);
    printf("\n");
    }
}
