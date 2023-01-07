#include <stdio.h>
#include <string.h>


int lengthOfLongestSubstring(char * s){
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)*(s+start)] = 1;
    
    while( *(s+end) != 0 )
    {
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] )//将要加入的新元素与map内元素冲突
        {
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }
    
    return maxlen;
}

char *str1 = "abcabcbb";
char *str2 = "bbbbb";
char *str3 = "pwwkew";

int main() {
    int ret = 0;

    ret = lengthOfLongestSubstring(str1);
    printf("%s, %d\n", str1, ret);

    ret = lengthOfLongestSubstring(str2);
    printf("%s, %d\n", str2, ret);

    ret = lengthOfLongestSubstring(str3);
    printf("%s, %d\n", str3, ret);

}
