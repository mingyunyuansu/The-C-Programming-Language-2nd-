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

int delete_space(char * line, int len) {
    //这里需要注意，如果一行仅包含一个'\n'和'\0'，那么按照题意应该保留
    if (len == 1) return len;

    for (len -= 2; (line[len] == ' ' || line[len] == '\t') && len >= 0 ; --len) {
        line[len] = '\0';
    }
    if (len < 0)
        return 0;
    else {
        line[++len] = '\n';
        return (len + 1);
    }      
}

int main() {
    char line[MAXLINE];
    int len;
    while ((len = getline(line)) > 0) {
        if (delete_space(line, len) > 0) {
            printf("%s", line);
        }
    }
    return 0;
}