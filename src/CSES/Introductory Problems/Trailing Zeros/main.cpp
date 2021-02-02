/*
 * Trailing Zeros
 * https://cses.fi/problemset/task/1618
 */

#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[]) {
    uint n_max;
    long long count_5 = 0LL;

    cin >> n_max;

    // The solution is to count the numbers 2 and 5 as factors of n!
    // Because 2 is more likely than 5 in n!
    // we only need to count the amount of 5 factors.

    // n / 5 counts how many numbers from 1 to n are divisible by 5
    // so they have at least one factor 5

    // To count the numbers that have two 5 as factors
    // we divide n / (5x5), so this tell us how many numbers are divisible
    // by 25 and then they have 5x5 as factor.

    // We can make this procedure to count all the factors of 5 in n!

    for (uint i = 5; n_max / i >= 1; i *= 5) {
        count_5 += n_max / i;
    }

    cout << count_5 << "\n";

    return 0;
}
