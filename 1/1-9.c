#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF){
        if (c != ' ') putchar(c);
        else {
            //脑中浮现出自动机。。。
            putchar(c);
            do
            c = getchar();
            while (c == ' ' && c != EOF);
            if (c != EOF)
            putchar(c);
        }
    }
    return 0;
}