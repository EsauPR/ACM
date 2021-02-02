/*
 * Bit Strings
 * https://cses.fi/problemset/task/1617
 */

#include <iostream>

using namespace std;

#define MOD 1000000007

int main(int argc, char const *argv[]) {
    uint n;

    cin >> n;

    long long ans = 2LL;
    for (uint i = 1; i < n; i++) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
