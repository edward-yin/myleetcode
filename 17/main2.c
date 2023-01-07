#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *key[] = {
    "abc", 
    "def", 
    "ghi", 
    "jkl", 
    "mno", 
    "pqrs", 
    "tuv", 
    "wxyz"
    };

char *digits_T = NULL;
int digitLen = 0;

char **combinations = NULL;
int combinations_size = 0;

char *combination = NULL;
int combination_size = 0;



void combinate(int index) {
    int i = 0;
    if (index == digitLen) {
        char *tmp = malloc(sizeof(char) * combination_size + 1);
        memcpy(tmp, combination, combination_size + 1);
        combinations[combinations_size++] = tmp;
    } else {
        // char digit = digits_T[index];
        char *letters = key[digits_T[index] - '0' - 2];
        int letterSize = strlen(letters);

        for (i = 0; i < letterSize; i++) {
            combination[combination_size++] = letters[i];
            combination[combination_size] = 0;
            combinate(index + 1);
            combination[--combination_size] = 0;
        }
    }

}

char ** letterCombinations(char * digits, int* returnSize) {
    combinations_size = combination_size = 0;
    digitLen = strlen(digits);

    if (digitLen == 0) {
        *returnSize = 0;
        return NULL;
    } else {
        digits_T = digits;
        int num = 1, i = 0;

        for (i = 0; i < digitLen; i++) {
            num *= 4;
        }

        combinations = malloc(sizeof(char*) * num);
        combination = malloc(sizeof(char*) * digitLen);
        combinate(0);
        *returnSize = combinations_size;
        return combinations;
    }
}

int main () {
    char **combin = NULL;
    int combinSize = 0, i = 0;

    {
        combinations_size = combination_size = 0;
        char *str = "23";
        printf("%s:\n", str);
        combin = letterCombinations(str, &combinSize);
        for (i = 0; i < combinSize; i++) {
            printf("%s, ", combin[i]);
        }
        printf("\n");
    }

    {
        combinations_size = combination_size = 0;
        char *str = "2";
        printf("%s:\n", str);
        combin = letterCombinations(str, &combinSize);
        for (i = 0; i < combinSize; i++) {
            printf("%s, ", combin[i]);
        }
        printf("\n");
    }

    {
        combinations_size = combination_size = 0;
        char *str = "458";
        printf("%s:\n", str);
        combin = letterCombinations(str, &combinSize);
        for (i = 0; i < combinSize; i++) {
            printf("%s, ", combin[i]);
        }
        printf("\n");
    }
}