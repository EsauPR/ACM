/*
 * Missing Number
 * https://cses.fi/problemset/task/1083/
 */

#include <iostream>
#include <ios>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n_numbers, num, tmp;

    cin >> n_numbers;
    num = (n_numbers * (n_numbers + 1)) / 2;

    n_numbers--;
    while (n_numbers --) {
        cin >> tmp;
        num -= tmp;
    }

    cout << num << "\n";

    return 0;
}
