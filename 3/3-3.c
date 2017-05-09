#include <stdio.h>
#define LEN 1024

void expand(char * s1, char * s2);

int main(int argc, char ** argv){
    char s1[1024], s2[1024];
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        s1[i++] = c;
    }
    s1[i] = '\0';
    expand(s1, s2);
    printf("%s", s1);
    printf("%s", s2);
    return 0;
}

void expand(char * s1, char * s2) {
    int i, j, t;
    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        if (s1[i] != '-') s2[j++] = s1[i];
        else {
            if (s1[i - 1] >= s1[i+1]) {
                s2[j++] = '-';
                continue;
            }
            if (s1[i-1] >= 'a' && s1[i-1] <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z') {
                t = s1[i - 1] + 1;
                while (t <= s1[i+1]) {
                    s2[j++] = t;
                    t++;
                }
            }
            else if (s1[i-1] >= '0' && s1[i-1] <= '9' && s1[i+1] >= '0' && s1[i+1] <= '9') {
                t = s1[i - 1] + 1;
                while (t <= s1[i+1]) {
                    s2[j++] = t;
                    t++;
                }
            }
            else if (s1[i-1] >= 'A' && s1[i-1] <= 'Z' && s1[i+1] >= 'A' && s1[i+1] <= 'Z') {
                t = s1[i - 1] + 1;
                while (t <= s1[i+1]) {
                    s2[j++] = t;
                    t++;
                }
            }
        i++;
        }
    }
    s2[j] = '\0';
}