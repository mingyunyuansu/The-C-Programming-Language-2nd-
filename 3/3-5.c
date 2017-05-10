#include <stdio.h>
#include <string.h>

#define abs(x) ((x) > 0? (x): -(x))

void itob(int n, char *s, int b);
void reverse(char *s);

int main(int argc, char ** argv){
    int n = atoi(argv[1]);
    int b = atoi(argv[2]);
    char s[1024];
    itob(n, s, b);
    printf("%s", s);
    return 0;
}

void itob(int n, char *s, int b) {
    char c;
    int i = 0, sign = n;
    while (n != 0) {
        c = abs(n % b);
        if (c <= 9)
            c += '0';
        else {
            c = c - 10 + 'a';
        }
        s[i++] = c;
        n /= b;
    }
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char *s) {
    int i, tmp, len = strlen(s);
    for (i = 0; i < strlen(s) / 2; ++i) {
        tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}