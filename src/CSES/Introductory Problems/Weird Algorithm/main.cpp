/*
 * Weird Algorithm
 * https://cses.fi/problemset/task/1068/
 */

#include <iostream>
#include <ios>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long num = 0;

    cin >> num;

    cout << num;

    while(num != 1) {
        if (num % 2 == 0) {
            num /= 2LL;
        } else {
            num = num * 3 + 1;
        }

        cout << " " << num;
    }


    return 0;
}
