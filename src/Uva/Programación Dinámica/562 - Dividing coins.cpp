/*
    Problem: 562 - Dividing coins
    url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=503
*/

#include <stdio.h>

#define MAX_WEIGHT 50001
#define MAX_COINS 101
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int DP[MAX_COINS][MAX_WEIGHT];


void knapsack(int ncoins, int *coins, int weight) {
    for (int i = 1; i <= ncoins; i++) {
        for (int j = 0; j <= weight; j++) {
            DP[i][j] = DP[i - 1][j];
            if (coins[i] <= j) {
                DP[i][j] = MAX(DP[i][j], coins[i] + DP[i-1][j - coins[i]]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int ncases;
    int coins[MAX_COINS];
    coins[0] = 0;

    scanf("%d", &ncases);

    while(ncases--) {
        int ncoins, weight = 0;
        scanf("%d", &ncoins);

        for (int i = 1; i <= ncoins; i++) {
            scanf("%d", &coins[i]),
            weight += coins[i];
        }

        knapsack(ncoins, coins, weight / 2);
        printf("%d\n", weight - DP[ncoins][weight / 2] * 2);
    }

    return 0;
}
