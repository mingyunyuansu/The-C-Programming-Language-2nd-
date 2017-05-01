#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main(int argc, char ** argv) {
    printf("%d\n", invert(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    return x ^ ((~(~0 << n)) << (p - n));
}