/*
 * Apple division
 * https://cses.fi/problemset/task/1623
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long get_min_diff(vector<long long>& weights, long long t_sum, uint pos=0, long long c_sum=0) {
    long long c_diff = abs(t_sum - 2 * c_sum);

    if (pos == weights.size()) {
        return c_diff;
    }

    long long sum_y = get_min_diff(weights, t_sum, pos + 1, c_sum + weights[pos]);
    long long sum_n = get_min_diff(weights, t_sum, pos + 1, c_sum);

    return min(sum_y, sum_n);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n_apples;
    long long weight, w_sum=0;
    vector<long long> weights;

    cin >> n_apples;
    while (n_apples--) {
        cin >> weight;
        weights.push_back(weight);
        w_sum += weight;
    }

    cout << get_min_diff(weights, w_sum) << "\n";

    return 0;
}
