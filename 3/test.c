#include <stdio.h>

int main(int argc, char ** argv) {
    int n = atoi(argv[1]);
    printf("%d", n % 16);
    return 0;
}