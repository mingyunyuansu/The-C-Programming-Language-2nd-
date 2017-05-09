//基本思路就这样了，没什么好做的
#include <stdio.h>
#define LEN 1024

void escape(char * s, char * t);
void show_char(char *s, char * t);

int main(int argc, char ** argv){
    char *s = argv[1];
    char t1[LEN];
    char t2[LEN];
    escape(s, t1);
    //show_char(s, t2);
    return 0;
}

void escape(char * s, char * t) {
    int i, j;
    for (i = 0, j = 0; s[i]!='\0' && i < LEN && j < LEN; i++) {
        switch (s[i]) {
            case '\n': t[j++] = '\\';
                       t[j++] = 'n';
                       break;
            case '\t': t[j] = '\\';
                       t[j+1] = 't';
                       j+=2;
                       break;
            case ' ': t[j++] = '(';
                      t[j++] = 's';
                      t[j++] = 'p';
                      t[j++] = 'a';
                      t[j++] = 'c';
                      t[j++] = 'e';
                      t[j++] = ')';
                      break;
            default: t[j++] = s[i];
        }
    }
    if (s[i] == '\0') {
        t[j++] = '\\';
        t[j++] = '0';
        t[j] = '\0';
    }
    printf("%s\n", t);
}

void show_char(char *s, char * t){}
