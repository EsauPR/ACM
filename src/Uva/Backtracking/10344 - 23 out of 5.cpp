/*
    Problem: 10344 - 23 out of 5
    url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1285
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 5
#define MAX_OPERATORS 3
#define TAKED 1
#define UNTAKED 0

int numbers[2][MAX_NUMBERS];
char operators[3] = {'+', '-', '*'};

int make_operation(char operatr, int value1, int value2) {
    if (operatr == '+') {
        return value1 + value2;
    }
    if (operatr == '-') {
        return value1 - value2;
    }
    return value1 * value2;
}

bool solve(int num_taked, int value) {
    if (num_taked == 5) {
        if (value == 23) {
            return true;
        }
        return false;
    }

    for (int i = 0; i < MAX_NUMBERS; ++i) {
        if (numbers[1][i] == UNTAKED) {
            numbers[1][i] = TAKED;
            for (int j = 0; j < MAX_OPERATORS; j++) {
                int current_value = make_operation(operators[j], value, numbers[0][i]);
                if (solve(num_taked + 1, current_value)) {
                    return true;
                }
            }
            numbers[1][i] = UNTAKED;
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {

    while(true) {
        bool finish = true;
        for (int i = 0; i < MAX_NUMBERS; i++){
            numbers[1][i] = 0;
            scanf("%d", &numbers[0][i]);
            if (numbers[0][i] != 0) {
                finish = false;
            }
        }

        if (finish) {
            break;
        }

        bool solution = false;
        for (int i = 0; i < MAX_NUMBERS; i++) {
            numbers[1][i] = 1;
            if (solve(1, numbers[0][i])) {
                solution = true;
                break;
            }
            numbers[1][i] = UNTAKED;
        }

        if (solution) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}
