/*
 * Permutations
 * https://cses.fi/problemset/task/1070
 */

#include <ios>
#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    if (num==1) {
        cout << 1;
        return 0;
    }

    if (num == 2 || num == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    if (num == 4) {
        cout << "2 4 1 3";
        return 0;
    }

    int limit = (num % 2 == 0)? num/2 : num/2+1;

    for (int i=1; i<=limit; i++) {
        if (num % 2 != 0 && i == limit) {
            cout << i;
            continue;
        }
        cout << i << " " <<limit+i;
        if (i!=limit) {
            cout << " ";
        }
    }

    return 0;
}
