/*
 * Number Spiral
 * https://cses.fi/problemset/task/1071
 */

#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases, row, col;

    cin >> cases;

    while (cases--) {
        cin >> row >> col;
        long long diag_pos = max(row, col) - 1;
        long long diag_value = diag_pos*diag_pos + diag_pos + 1;

        if (col == row) {
            cout << diag_value << "\n";
            continue;
        }

        if (col < row) {
            if (row % 2 == 0) {
                diag_value += row - col;
            } else {
                diag_value -= row - col;
            }
        } else {
            if (col % 2 == 0) {
                diag_value -= col - row;
            } else {
                diag_value += col - row;
            }
        }

        cout << diag_value << "\n";
    }

    return 0;
}
