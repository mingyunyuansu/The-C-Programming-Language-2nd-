#include <stdio.h>
#include <string.h>

void squeeze1(char *s1, char * s2);

void squeeze(char *s1, char * s2);

int main(int argc, char ** argv) {
    squeeze(argv[1], argv[2]);
    return 0;
}
//原来这一题那么难。。。子串搜索问题，下面的squeeze1解法已经可以适应大部分情况了，但是还是不能做到“前置”预测，即1112中找112，还是找不到，最后只能考虑暴力方法了。
void squeeze1(char *s1, char * s2) {
    int i = 0, m = 0;
    char st[strlen(s1) + 1];
    for (; s1[i] != '\0'; ++i) {
        if (s1[i] != s2[0]) {
            st[m++] = s1[i];
        }
        else {
            int j, t = i + 1;
            for (j = 1; s1[t] == s2[j] && j < strlen(s2); t++, j++)
            ;
            if (j == strlen(s2))
                i = t - 1;
            else {
                while (i < t) {
                    st[m++] = s1[i++];
                }
                --i;
            }
        }
    }
    st[m] = '\0';
    printf("%s\n", st);
}

void squeeze(char * s1, char * s2) {
    //暴力方法，遍历整个s1，确定s2是否是其子串,将子串全部手动删除
    //然后再开始字符串拷贝
    char st[strlen(s1) + 1];
    int i, len_of_s1 = strlen(s1), m = 0;//因为子串用'\0'替代，破坏了%s的结构，所以需要先保存s1长度
    for (i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == s2[0]) {
            int t = i + 1, j = 1;
            for (; s1[t] == s2[j] && j < strlen(s2); ++j, ++t)
            ;
            if (j == strlen(s2)){
                while (i != t) {
                    s1[i++] = '\0';
                }
                i--;//因为循环尾还会加1，因此这里要退回一位
            }
        }
    }
    for (i = 0; i < len_of_s1; i++) {
        if (s1[i] != '\0') st[m++] = s1[i];
    }
    st[m] = '\0';
    printf("%s\n", st);
}