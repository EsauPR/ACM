/**
 * Problem: The Power Sum
 * url: https://www.hackerrank.com/challenges/the-power-sum
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power_sum(int X, int N, int num) {
    int count = 0;
    int num_pow = pow(num, N);
    
    if (num_pow == X)
        return 1;
    if (num_pow > X)
        return 0;

    
    for (num += 1; (int)pow(num, N) <= X; num++) {
        count += power_sum(X - num_pow, N, num);
    }
    
    return count;
}

int main(int argc, const char *argv[]) {
    int X, N, count=0, i;
    
    scanf("%d\n%d", &X, &N);
    for (i=1; (int)pow(i, N) <= X; i++) {
        count += power_sum(X, N, i);
    }
    
    printf("%d\n", count);

    return 0;
}

