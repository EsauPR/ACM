/*
    Problem: 11137 - Ingenuous Cubrency
    url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2078&mosmsg=Submission+received+with+ID+22398577
*/

#include <stdio.h>

#define MAX_CHANGE 10001
#define NUM_COINS 22

long long int DP[NUM_COINS][MAX_CHANGE];
int coins[NUM_COINS] = {0 , 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

void solve() {
    DP[0][0] = 1LL;

    for (int i = 1; i < NUM_COINS; i++) {
        for (int j = 0; j < MAX_CHANGE; j++) {
            DP[i][j] = DP[i - 1][j];
            if (coins[i] <= j) {
                DP[i][j] += DP[i][j - coins[i]];
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int number;
    solve();

    while(scanf("%d", &number) != EOF) {
        printf("%lld\n", DP[NUM_COINS - 1][number]);
    }

    return 0;
}
