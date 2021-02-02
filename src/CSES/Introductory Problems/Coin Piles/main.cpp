/*
 * Coin Piles
 * https://cses.fi/problemset/task/1754
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int ncases;
    double n1, n2;

    cin >> ncases;

    while(ncases--) {
        cin >> n1 >> n2;

        // 2x +  y = n1
        //  x + 2y = n2

        bool nice = true;
        double y1 = (n1 - 2 * n2) / (-3.0);
        double y2 = (n2 - 2 * n1) / (-3.0);

        if (!(y1>=0 && (y1 - (int)y1) == 0.0)) {
            nice = false;
        }
        if (!(y2>=0 && (y2 - (int)y2) == 0.0)) {
            nice = false;
        }

        if (nice) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
