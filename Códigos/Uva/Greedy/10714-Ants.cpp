/**
 * Problem: Ants
 * Problem ID: 10714
 * url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1655
 */

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b))? (a):(b))
#define max(a, b) (((a) > (b))? (a):(b))

int main(int argc, char const *argv[]) {
    int ncases, length, nAnts;
    int earliestTime, latestTime;
    int distance;

    scanf("%d", &ncases);

    while(ncases--) {
        scanf("%d %d", &length, &nAnts);
        earliestTime = latestTime = 0;

        for (int i = 0; i < nAnts; i++) {
            scanf("%d", &distance);
            earliestTime = max(earliestTime, min(distance, length - distance));
            latestTime = max(latestTime, max(distance, length - distance));
        }

        printf("%d %d\n", earliestTime, latestTime);
    }

    return 0;
}
