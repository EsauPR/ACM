/**
    Problem: 10038 - Jolly Jumpers
    url: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=979
**/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
    int n;

    while(cin >> n) {
        // cout << "n: " << n << endl;

        vector<bool> bucket(n, false);

        int n_prev, n_current;

        cin >> n_prev;

        for (int i = 0; i < n - 1; i++) {
            cin >> n_current;

            int diff = abs(n_prev - n_current);
            n_prev = n_current;

            if (diff >= n) continue;

            bucket[diff] = true;
        }

        if (n == 1) {
            cout << "Jolly" << endl;
            continue;
        }

        bool all = true;

        for (int i = 1; i < n; i++) {
            if(!bucket[i]) all = false;
        }

        if (all) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }

    return 0;
}
