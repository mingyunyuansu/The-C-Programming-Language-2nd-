#include <ctype.h>
#include <stdio.h>

double atof(char *s);

int main(int argc, char **argv) {
  double n = atof(argv[1]);
  printf("%lf", n);
  return 0;
}

double atof(char *s) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++) //这个处理有点厉害。。。
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (
      power = 1.0; isdigit(s[i]);
      i++) { //这里也有意思，先把整个数字当做没有小数部分来处理，最后再一次性把小数点左移
    // printf("%lf\n", val);
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    //理论上指数应该也可以是浮点数，但是那样我就不会计算值了，所以这里假设e后面的指数是整数
    i++;
    int sign_power;
    if (s[i] == '-') {
      sign_power = -1;
      i++;
    } else if (s[i] == '+') {
      sign_power = 1;
      i++;
    } else
      sign_power = 1;

    int val_power = 0;
    for (; isdigit(s[i]); i++) {
      val_power = val_power * 10 + s[i] - '0';
    }
    while (val_power != 0) {
      if (sign_power == 1) {
        power /= 10.0;
      } else {
        power *= 10.0;
      }
      val_power--;
    }
  }
  return sign * val / power;
}