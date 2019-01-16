/*
    10344 - 23 out of 5
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1285
*/

#include <stdio.h>

#define MAX_OPERATORS 3

int numbers[5];

int make_operation(int operation, int value1, int value2) {
    if (operation == 0) {
        // printf(" + ");
        return value1 + value2;
    }
    if (operation == 1) {
        // printf(" - ");
        return value1 - value2;
    }
    // printf(" * ");
    return value1 * value2;
}


int find_formule(int position, int value ) {
    if (position == 5) {
        if (value == 23) {
            return true;
        }
        return false;
    }

    for (int i = 0; i < MAX_OPERATORS; i++) {
        // printf("%d: %d ", position, value);
        int tmp_value = make_operation(i, value, numbers[position]);
        // printf(" %d = %d \n", numbers[position], tmp_value);
        if (find_formule(position + 1, tmp_value)) {
            return true;
        }
    }

    return false;
}


int main(int argc, char const *argv[]) {
    while(true) {
        bool last_case = true;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &numbers[i]);
            if (numbers[i] != 0) {
                last_case = false;
            }
        }

        if (last_case) {
            break;
        }

        if (find_formule(1, numbers[0])) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
