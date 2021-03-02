/*
 * Gray Code
 * https://cses.fi/problemset/task/2205
 */

/*
 * Best solution is: graycode from wikipedia
 * i ^ (i >> 1) for i in 0:2^n
 */

#include <iostream>
#include <cmath>

using namespace std;

void print(int bstring, int size) {
    for (int i = size - 1; i >= 0 ; i--) {
        cout << ((bstring & (1 << i))? "1": "0");
    }
    cout << "\n";
}

void gen(int size, int pos, int & bstring) {
    if (pos == 0) {
        print(bstring, size);
        return;
    }

    gen(size, pos - 1, bstring);
    bstring ^= (1 << (pos - 1));
    gen(size, pos - 1, bstring);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int bstring = 0, size;
    cin >> size;
    gen(size, size, bstring);

    return 0;
}
