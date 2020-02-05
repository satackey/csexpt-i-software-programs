#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

short getRandPointOnCircle(void);


int main(void) {
    int n;
    printf("nを入力: ");
    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        short onCircle = getRandPointOnCircle();
        if (onCircle) {
            ++count;
        }
    }

    double pi = (double)count * 4 / n;
    printf("%f\n", pi);

    return 0;
}

short getRandPointOnCircle(void) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;
    double hypotenuse = x*x + y*y;

    if (hypotenuse <= 1) {
        return 1;
    }

    return 0;
}
