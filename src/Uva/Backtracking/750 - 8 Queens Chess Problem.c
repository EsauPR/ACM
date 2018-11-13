 /**
 * Problem: 8 Queens Chess Problem
 * Id: 750
 * url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565
 */

#include <stdio.h>
#include <string.h>

#define abs(x)  (((x) < 0)? -(x):(x))
#define BOARD_SIZE 9

int solution[BOARD_SIZE];
int solutions_count = 0;


void print_sol() {
    printf("%2d     ", ++solutions_count);
    for (int i = 1; i < BOARD_SIZE; i++) {
        printf(" %d", solution[i]);
    }
    puts("");
}


int valid_position(int row, int column) {
    for (int column_i = 1; column_i < BOARD_SIZE; column_i++) {
        // Not queen in the column
        if (solution[column_i] == -1) {
            continue;
        }
        // Same column or row
        if (solution[column_i] == row || column_i == column) {
            return 0;
        }
        // Diagonal
        if (abs(solution[column_i] - row) == abs(column_i - column) ) {
            return 0;
        }
    }

    return 1;
}


void place_queen(int column) {
    if (column == BOARD_SIZE) {
        print_sol();
        return;
    }

    if (solution[column] != -1) {
        place_queen(column + 1);
        return;
    }

    for (int row = 1; row < BOARD_SIZE; row++) {
        if (valid_position(row, column)) {
            solution[column] = row;
            place_queen(column + 1);
        }
        solution[column] = -1;
    }
}


int main(int argc, char const *argv[]) {
    int cases;
    scanf("%d", &cases);

    while(cases--) {
        int startx, starty;
        memset(solution, -1, sizeof(solution));
        solutions_count = 0;

        scanf("%d %d", &starty, &startx);
        solution[startx] = starty;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        place_queen(1);
        if (cases) {
            puts("");
        }
    }
    return 0;
}
