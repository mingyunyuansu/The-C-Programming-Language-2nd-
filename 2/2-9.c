#include <stdio.h>

int bitcount(unsigned x);

int main(int argc, char ** argv) {
    printf("%d\n", bitcount(atoi(argv[1])));
    return 0;
}

int bitcount(unsigned x) {
    int cnt = 0;
    while (x != 0) {
        x &= (x-1);//可以删除x中最右的一个1位
        cnt++;
    }
    return cnt;
}