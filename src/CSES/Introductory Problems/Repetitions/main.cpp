/*
 * Repetitions
 * https://cses.fi/problemset/task/1069/
 */

#include <ios>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int longest = 1, count = 1;
    char last_char = str[0];
    for (uint i = 1; i < str.size(); i++) {
        if (str[i] == last_char) {
            count ++;
            if (count > longest) {
                longest = count;
            }
        } else {
            count = 1;
        }
        last_char = str[i];
    }

    cout << longest << "\n";

    return 0;
}
