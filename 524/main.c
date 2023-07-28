#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int CompStr(const void *a, const void *b)
{
    const char *a1 = *(const char **)a;
    const char *b1 = *(const char **)b;

    if (strlen(a1) < strlen(b1)) {
        return 1;
    } else if (strlen(a1) == strlen(b1)) {
        return strcmp(a1, b1);
    }
    return -1;
}
char * findLongestWord(char * s, char ** dictionary, int dictionarySize){
    qsort(dictionary, dictionarySize, sizeof(char *), CompStr);

    for (int i = 0; i < dictionarySize; i++) {
        int sameNum = 0;
        int lastPos = 0;
        for (int j = 0; j < strlen(dictionary[i]); j++) {

            for (int k = lastPos; k < strlen(s); k++) {
                if (dictionary[i][j] == s[k]){
                    sameNum++;
                    lastPos = k + 1;
                    break;
                }
            }
            if (sameNum == strlen(dictionary[i])) {
                return dictionary[i];
            }
        }
    }

    return "";
}

int main()
{

}
