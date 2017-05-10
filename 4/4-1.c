//这题题目表意不明，我只能理解为从右倒着数来匹配，如ABCD，匹配DC，返回3
#include <stdio.h>
#include <string.h>

int strrindex(char *s, char *t);
int main(int argc, char ** argv){
    int i = strrindex(argv[1], argv[2]);
    printf("%d", i);
    return 0;
}

int strrindex(char *s , char * t) {
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = 0; j >= 0 && t[k] != '\0' && s[j] == t[k]; --j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}