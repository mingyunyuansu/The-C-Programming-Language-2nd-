#include <stdio.h>

int main(){
    int test;
    test = (getchar() != EOF);
    printf("getchar() != EOF:%d\n", test);
    printf("EOF: %d\n", EOF);
    return 0;
}
/*结果是
getchar() != EOF:1
EOF: -1
第一句的值恒为1
*/