/*
挺轻松就自主完成了，甚至没仔细想。。。记得大一时看这个的例题愣是看不懂，看答案也倒腾了半天出不来。
一对比，虽然自己没有什么感觉，但看来确实这一两年还是有进步的，依然很菜就是了。
*/
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c, state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN){
                putchar('\n');
            }
            state = OUT;
            continue;
        }
        if (state == IN) putchar(c);
        else if (state == OUT) {
            state = IN;
            putchar(c);
        }
    }
}