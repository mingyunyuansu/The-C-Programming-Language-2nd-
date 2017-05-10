//补码的表示范围是 -2^(字长-1)~2^(字长-1)-1，最小的负数无法转成相应的正数
#include <stdio.h>
#include <string.h>

#define abs(x) (x>0?x:-x)

void itoa(int n, char s[]);
void reverse(char * s);

int main(int argc, char ** argv){
    int n = atoi(argv[1]);
    char s[1024] = {0};
    itoa(n, s);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
    s[i++] = '-';
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