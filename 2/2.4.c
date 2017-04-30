#include <stdio.h>

void squeeze(char *s1, char * s2);

int main(int argc, char ** argv) {
    squeeze(argv[1], argv[2]);
    return 0;
}

void squeeze(char *s1, char * s2) {
    int i = 0, m = 0;
    char st[strlen(s1)];
    for (; s1[i] != '\0'; ++i) {
        if (s1[i] != s2[0]) {
            st[m++] = s1[i];
        }
        else {
            int j, t = i;
            for (j = 1; s1[t] == s2[j] && j < strlen(s2); t++, j++) {

            }
            if (j == strlen(s2))
                i += j;
        }
    }
    printf("%s\n", st);
}