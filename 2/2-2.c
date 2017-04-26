#include <stdio.h>

int main()
{
    int x = 1, i = 0, lim = 10, c;
    while (x != 0) {
        if (i >= lim - 1) {
            x = 0;
            continue;
        }
        if ((c = getchar()) == '\n') {
            x = 0;
            continue;
        }
        if (c == EOF) {
            x = 0;
            continue;
        }
        ++i;
    }
    return 0;
}
