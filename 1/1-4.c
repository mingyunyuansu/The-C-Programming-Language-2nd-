#include <stdio.h>

main() {
    double celsius, fahr;
    int low = -17, high = 148, step = 10;
    celsius = low;
    while (celsius <= 100) {
        fahr = (9/5.0) * celsius + 32;
        printf("%3.0lf\t%6.1lf\n", celsius, fahr);
        celsius += step;
    }
}
