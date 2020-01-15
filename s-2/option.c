#include <stdio.h>

int middle_square(int);

int main(void) {
    int seed;

    printf("初期値: ");
    scanf("%d", &seed);

    for (int i = 0; i < 100; i ++) {
        seed = middle_square(seed);
        printf("%d\n", seed);
    }

    return 0;
}

int middle_square(int seed) {
    int squared = seed * seed;
    int splitted = squared / 100 % 10000;
    return splitted;
}
