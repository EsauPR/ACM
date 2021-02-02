/*
 * Increasing Array
 * https://cses.fi/problemset/task/1094/
 */

#include <ios>
#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_numbers, last_num, current_num;

    cin >> n_numbers >> last_num;
    n_numbers--;

    long long total = 0LL;
    while (n_numbers--) {
        cin >> current_num;
        if (current_num < last_num) {
            total += last_num - current_num;
            current_num = last_num;
        }
        last_num = current_num;
    }

    cout << total << "\n";

    return 0;
}
