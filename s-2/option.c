#include <stdio.h>

int middle_square(int);

int main(void) {
    int seed;

    printf("初期値: ");
    scanf("%d", &seed);

    for (int i = 0; i < 1000; i ++) {
        seed = middle_square(seed);
        printf("%4d: %d\n", i, seed);
    }

    return 0;
}

int middle_square(int seed) {
    int squared = seed * seed;
    int splitted = seed / 100 % 1000;
    return splitted;
}
