#include <stdio.h>

int main() {
    int fahr;
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d\t%6.1lf\n", fahr, (5/9.0)*(fahr-32));
    }
    return 0;
}