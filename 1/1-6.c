#include <stdio.h>

int main(){
    int test;
    test = (getchar() != EOF);
    printf("test:%d\n", test);
    return 0;
}