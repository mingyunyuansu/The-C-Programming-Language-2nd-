#include <stdio.h>

int lower(int c);

int main(int argc, char ** argv) {
    printf("%c->%c\n", argv[1][0], lower(argv[1][0]));
    return 0;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}