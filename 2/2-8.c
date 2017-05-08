#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(int argc, char ** argv) {
    printf("%x to %x\n", atoi(argv[1]), rightrot(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

unsigned rightrot(unsigned x, int n) { 
    return ((~((~0)<<n) & x) << (sizeof(x) * 8 - n)) | ((x>>n) & ~(~0<<(sizeof(x)*8 - n)));
}