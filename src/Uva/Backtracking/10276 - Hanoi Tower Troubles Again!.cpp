/*
    10276 - Hanoi Tower Troubles Again!
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1217
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_PEGS 50

int pegs[MAX_PEGS];


bool can_put_ball(int current_peg, int value) {
    if (pegs[current_peg] == 0)
        return true;

    int sum = pegs[current_peg] + value;
    if ((int)sqrt(sum) * (int)sqrt(sum) == sum)
        return true;
    return false;
}


int count_balls(int value, int total_pegs) {
    for (int i = 0; i < total_pegs; i++){
        if (can_put_ball(i, value)) {
            pegs[i] = value;
            return count_balls(value + 1, total_pegs);
        }
    }

    return value - 1;
}


int main(int argc, char const *argv[]) {
    int cases, total_pegs;
    scanf("%d", &cases);

    while(cases--) {
        memset(pegs, 0, sizeof(pegs));
        scanf("%d", &total_pegs);
        printf("%d\n", count_balls(1, total_pegs));
    }

    return 0;
}
