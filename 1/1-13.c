#include <stdio.h>

#define IN 0
#define OUT 1
#define LENGTH 21

int main() {
    int c, state = OUT, count = 0, rec[LENGTH] = {0}, i, j;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                state = OUT;
                rec[count]++;
                count = 0;
            }
        }
        else if (state == OUT) {
            state = IN;
            count++;
        }
        else
        count++;
    }
    for (i = 1; i < LENGTH; ++i) {
        printf("%d : ", i);
        for (j = 0; j < rec[i]; ++j)
            putchar('+');
        putchar('\n');
    }
    return 0;
}