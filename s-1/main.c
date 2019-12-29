#include <stdio.h>
#include <math.h>

int digitsToNum(int[4]);
void numToDigits(int, int[4]);
int get(short, int[4]);
void sortBy(int, int[4]);

int main(void) {
    int i = 0;

    int n;
    printf("正の整数（４桁）の入力: ");
    scanf("%d", &n);

    while (n != 0 && n != 6174) {
        int n_digits[4];
        numToDigits(n, n_digits);

        int n_max = get(0, n_digits);
        int n_min = get(1, n_digits);

        n = n_max - n_min;

        ++i;
    }

    printf("%d\n", i);

    return 0;
}

int digitsToNum(int n_digits[4]) {
    int n_num = 0;

    // n_digits の i 番目に対し 10^(4-i) を足していけば良い
    for (int i = 0; i < 4; ++i) {
        n_num += n_digits[i] * pow(10, 3-i);
    }

    return n_num;
}

void numToDigits(int n_int, int n_digits[4]) {
    // n 桁目は 10 の (n-1) 乗で割った答えを 10 で割ったあまり。
    for (int i = 4; i > 0; --i) {
        n_digits[4-i] = n_int / ((int)pow(10, i-1)) % 10;
    }
}

int get(short is_min, int n_digits[4]) {
    // 配列をコピー
    int sort_digits[4];
    for (int i = 0; i < 4; i++) {
        sort_digits[i] = n_digits[i];
    }
    
    sortBy(is_min, sort_digits);
    
    int n = digitsToNum(sort_digits);
    
    return n;
}

void sortBy(int is_asc, int n_digits[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j ++) {
            if (is_asc ? n_digits[i] > n_digits[j] : n_digits[i] < n_digits[j]) {
                int n_work;
                n_work = n_digits[i];
                n_digits[i] = n_digits[j];
                n_digits[j] = n_work;
            }
        }
    }
}
