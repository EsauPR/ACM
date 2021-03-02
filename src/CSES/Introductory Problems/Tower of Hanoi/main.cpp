/*
 * Tower of Hanoi
 * https://cses.fi/problemset/task/2165
 */

#include <iostream>
#include <cmath>

using namespace std;

void solve(int n, int t1, int t2, int t3) {
    // https://www.youtube.com/watch?v=LM68IQvIo_E
    if (n==0) {
        return;
    }
    solve(n - 1, t1, t3, t2);
    cout << t1 << " " << t3 << "\n";
    solve(n - 1, t2, t1, t3);
}

int main(int argc, char const *argv[]) {
    int n;

    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    solve(n, 1, 2, 3);
}
