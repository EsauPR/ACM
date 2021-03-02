/*
 * Digit Queries
 * https://cses.fi/problemset/task/2431
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


long long compute_limits(long long query, long long & down, long long & real_down) {
    long long up = 0LL;
    down = 1;
    real_down = 1LL;

    long long i=0;
    long long mypow = 1LL;
    for (; up < query; i++) {
        down = up;
        // cout << "down " << down << endl;
        // cout << "+ " << (9 * mypow) * (i + 1) << endl;

        up += (9 * mypow) * (i + 1);
        real_down *= 10;

        mypow *=10;
    }

    real_down = real_down / 10 - 1;

    return i;
}


int main(int argc, char const *argv[]) {
    long long n_queries;
    long long query, l_down, r_down;

    cin >> n_queries;

    while (n_queries--) {
        cin >> query;

        long long n_digits = compute_limits(query, l_down, r_down);

        // cout << "n_digits: " << l_down << "\tlow number: " << r_down << "\tsize: " << n_digits << endl;

        long long numbers_count_size_n = (query - l_down) / n_digits; // 5
        long long digits_count_missing = (query - l_down) % n_digits; // 1
        long long last_number = r_down + numbers_count_size_n;

        if (digits_count_missing == 0) {
            cout << last_number % 10 << "\n";
            continue;
        }


        last_number++;
        string number = to_string(last_number);
        cout << number[digits_count_missing - 1] << "\n";
    }

    return 0;
}
