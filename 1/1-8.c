#include <stdio.h>

int main() {
    int space, tab, wrap, c;
    space = tab = wrap = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
        space++;
        else if (c == '\t')
        tab++;
        else if (c == '\n')
        wrap++;
    }
    printf("space: %d, tab: %d, wrap: %d\n", space, tab, wrap);
    return 0;
}
/*windows下EOF通过ctrl-z输入，*nix是ctrl-d，
但是在Windows下的git bash按ctrl-d会直接停止，不过我用cmd测了一下程序没问题*/