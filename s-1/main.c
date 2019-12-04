#include <stdio.h>
#include <math.h>

int digitsToNum(int[4]);
void numToDigits(int, int[4]);
int getMax(int[4]);
int getMin(int[4]);
void getSortedBy(int, int[4]);

int main(void) {
    int i = 0;

    int n;
    scanf("%d", &n);

    while (n != 0 && n != 6174) {
        int n_digits[4];
        numToDigits(n, n_digits);

        int n_max = getMax(n_digits);
        int n_min = getMin(n_digits);

        n = n_max - n_min;

        ++i;
    }

    printf("%d", i);

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

int getMax(int n_digits[4]) {
    // 配列をコピー
    int desc_digits[4];
    for (int i = 0; i < 4; i++) {
        desc_digits[i] = n_digits[i];
    }

    getSortedBy(0, desc_digits);


    int n_max = digitsToNum(desc_digits);
    return n_max;
}

int getMin(int n_digits[4]) {
    // 配列をコピー
    int asc_digits[4];
    for (int i = 0; i < 4; i++) {
        asc_digits[i] = n_digits[i];
    }

    getSortedBy(1, asc_digits);

    int n_min = digitsToNum(asc_digits);
    return n_min;
}

void getSortedBy(int is_asc, int n_digits[4]) {
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



// https://marycore.jp/prog/c-lang/return-array/
// https://www.pc-master.jp/words/shojyun-kojyun.html
// https://programming-place.net/ppp/contents/c/rev_res/array004.html
// http://www.c-tipsref.com/reference/math/pow.html
// https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q1090279785
// http://www.ie.u-ryukyu.ac.jp/~e075769/study/study/c/ch7/7_10.php
