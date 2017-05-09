//补码的表示范围是 -2^(字长-1)~2^(字长-1)-1，最小的负数无法转成相应的正数
#include <stdio.h>

void itoa(int n, char s[]);

int main(int argc, char ** argv){}

void itoa(int n, char s[]) {
    int i, sign;
    unsigned m;
    sign = n;
    m = (unsigned)-n;
    
}