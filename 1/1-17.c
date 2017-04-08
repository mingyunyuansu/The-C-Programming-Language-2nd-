#include <stdio.h>

#define MAXLINE 1000

int getline(char* line) {
    int len = 0;
    char c;
    for (; (c = getchar()) != EOF && c != '\n' && len < MAXLINE; ++len) {
        line[len] = c;
    }
    if (c == '\n') {
        line[len++] = '\n';
    }
    line[len] = '\0';
    return len;
}

int main() {
    int len;
    char line[MAXLINE];
    while ((len = getline(line)) > 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }
    return 0;
}