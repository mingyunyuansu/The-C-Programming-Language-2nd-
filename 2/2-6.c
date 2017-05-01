#include <stdio.h>
#include <stdlib.h>
//这题的关键是，所谓第p位，指111000，从最右边的0往左数起的第p位，然后再往左数n位，是我们的目标
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char ** argv) {
    unsigned x = atoi(argv[1]);
    int p = atoi(argv[2]), n = atoi(argv[3]);
    unsigned y = atoi(argv[4]);

    printf("%d\n", setbits(x, p, n, y));
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ~((~(~0 << n)) << (p - 1))) | ((~(~0 << n) & y) << (p - 1));
}