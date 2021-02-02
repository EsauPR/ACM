/*
 * Two Sets
 * https://cses.fi/problemset/task/1092
 */

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    long long set1_sum=0LL, set2_sum=0LL;
    vector<long long> set1;
    vector<long long> set2;

    uint n;
    cin >> n;

    for (uint i = n; i>=1; i--) {
        if (set1_sum < set2_sum) {
            set1_sum += i;
            set1.push_back(i);
        } else {
            set2_sum += i;
            set2.push_back(i);
        }
    }

    if (set1_sum == set2_sum) {
        cout << "YES\n";

        cout << set2.size() << "\n";
        for(auto i : set2) {
            cout << i << " ";
        }
        cout << '\n';

        cout << set1.size() << "\n";
        for(auto i : set1) {
            cout << i << " ";
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
