/*
 * Palindrome Reorder
 * https://cses.fi/problemset/task/1755
 */

#include <iostream>

using namespace std;

#define SIZE 26

uint MEM[SIZE];

int main(int argc, char const *argv[]) {
    string phrase;
    cin >> phrase;

    for (auto cc : phrase) {
        if (cc == '\0') continue;
        MEM[cc - 'A'] ++;
    }

    int count = 0;
    char middle_char;
    uint middle_count = 0;
    for (uint i = 0; i <  SIZE; i++) {
        if (MEM[i] % 2 == 1) {
            count ++;
            middle_char = (char)('A' + i);
            middle_count = MEM[i];
        }
    }

    if (count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (uint i = 0; i < SIZE; i++) {
        if (MEM[i] % 2 != 0) {
            continue;
        }
        for (uint j = 0; j < MEM[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }

    for (uint j = 0; j <  middle_count; j++) {
            cout << middle_char;
    }

    for (int i = SIZE - 1; i >= 0; i--) {
        if (MEM[i] % 2 != 0) {
            continue;
        }
        for (uint j = 0; j <  MEM[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }

    cout << "\n";

    return 0;
}
