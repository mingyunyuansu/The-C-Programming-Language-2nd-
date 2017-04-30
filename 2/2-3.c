#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char *s)
{
    //这里i和j比较讲究，一个用来遍历字符串，一个用来计数
    int n, i, j, bit, sum = 0;
    n = strlen(s);
    //printf("n: %d\n", n);
    for (i = n - 1, j = 0; i >= 0; i--, j++)
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            bit = s[j] - '0';
        }
        else
        {
            bit = s[j] - 'a' + 10;
        }
        //printf("bit :%d\n", bit);
        sum += bit * pow(16, i);
    }
    return sum;
}

int main(int argc, char **argv)
{
    //注意，C中argv[0]是程序本身，argv[1]才是参数
    //printf("argc: %d, argv: %s", argc, argv[0]);
    int r = htoi(argv[1]);
    printf("%d\n", r);
    return 0;
}