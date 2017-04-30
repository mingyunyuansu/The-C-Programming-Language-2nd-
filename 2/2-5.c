#include <stdio.h>
#include <string.h>

int any(char * s1, char * s2) {
    int i = 0;
    for (; s1[i] != '\0'; ++i) {
        if (s1[i] == s2[0]) {
            int j = 1, t = i + 1;
            for (; s1[t] == s2[j] && j < strlen(s2); ++j, ++t)
            ;
            if (j == strlen(s2))
            return i;
        }
    }
    return -1;
}

int main(int argc, char * argv[]) {
    printf("%d\n", any(argv[1], argv[2]));
    return 0;
}