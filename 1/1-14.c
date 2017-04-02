#include <stdio.h>
//有没有搞错，这题比上题好写多了啊
int main() {
    int c, count[150] = {0};
    while ((c = getchar()) != EOF) {
        count[c]++;
    }
    int i, j;
    for (i = 0; i < 150; ++i) {
        if (count[i] == 0) continue;
        putchar(i);
        putchar(' ');
        for (j = 0; j < count[i]; ++j)
            putchar('+');
        putchar('\n');
    }
    return 0;
}