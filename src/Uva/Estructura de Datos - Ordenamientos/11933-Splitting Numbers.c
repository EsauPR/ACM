/**
 * Problem: Splitting Numbers
 * Problem ID: 11933
 * url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3084
 */

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int number;

    while(scanf("%d", &number), number) {
        int a = 0;
        int b = 0;

        for (int i = 0, j = 0; i < 31; i++) {
            if (number & (1 << i)) {
                if (j++ & 1) {
                    a = a | (1 << i);
                } else {
                    b = b | (1 << i);
                }
            }
        }

        printf("%d %d\n", b, a);
    }

    return 0;
}
