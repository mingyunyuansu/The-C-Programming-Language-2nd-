#include <stdio.h>
#define MAXLINE 1000

int getline(char * line) {
    /*如果只有一个换行符，那么长度为1，line[0] = '\n', line[1] = '\0'*/
    int len;
    char c;
    for (len = 0; len < MAXLINE && (c = getchar()) != EOF && c != '\n'; len++) {
        line[len] = c;
    }
    if (c == '\n') {
        line[len++] = c;   
    }
    line[len] = '\0';
    return len;
}

void reverse(char * line, int len) {
    int i;
    for (i = 0; i < len/2; ++i) {
        char tmp = line[i];
        line[i] = line[len - i - 2];//'\n'依然放在最后
        line[len - i - 2] = tmp;
    }
}

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}