/*
    Problem: 10130 - SuperSale
    url: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071
*/

#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define Wi 1
#define Vi 0

int DP[1001][31];
int items[2][1001], people[100];

void knapsack(int maxWeight, int nItems) {
    for (int i = 1; i <= nItems; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            DP[i][j] = DP[i - 1][j];
            if (items[Wi][i] <= j) {
                DP[i][j] = MAX(DP[i][j], items[Vi][i] + DP[i - 1][j - items[Wi][i]]);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int cases;
    scanf("%d", &cases);

    while(cases--) {
        int nelements, npeople, max = -1;

        // Leemos los objetos valor-peso
        scanf("%d", &nelements);
        for (int i = 1; i <= nelements; i++) {
            scanf("%d %d", &items[Vi][i], &items[Wi][i]);
        }

        // Leemos la capacidad de carga de cada persona
        scanf("%d", &npeople);
        for (int i = 1; i <= npeople; i++) {
            scanf("%d", &people[i]);
            max = MAX(max, people[i]);
        }


        knapsack(max, nelements);;

        int totalWeight = 0;
        for (int i = 1; i <= npeople; i++) {
            totalWeight += DP[nelements][people[i]];
        }

        printf("%d\n", totalWeight);
    }
    return 0;
}
