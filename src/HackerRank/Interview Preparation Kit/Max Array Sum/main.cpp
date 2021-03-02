#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int find_max_sum(vector<int>&arr, vector<int>&dp, int pos) {
    if (pos == 0 || pos == 1) return 0;
    if (dp[pos] != -1) return dp[pos];

    int elm = max(arr[pos], 0);

    int sum = max(elm, max(find_max_sum(arr, dp, pos-1), find_max_sum(arr, dp, pos-2) + elm));

    dp[pos] = sum;

    return sum;
}


int main() {
    int nelemns;
    vector<int> arr;

    cin >> nelemns;

    arr.push_back(0);
    arr.push_back(0);

    while(nelemns--) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    // vector<int> dp(arr.size(), 0);

    // for (uint i = 2; i < arr.size(); i++) {
    //     int elm = max(arr[i], 0);
    //     dp[i] = elm; // Tomar el número por si solo como un subset
    //     dp[i] = max(dp[i], max(elm + dp[i-2], dp[i-1]));
    // }

    // cout << dp[dp.size()-1] << "\n";

    vector<int> dp(arr.size(), -1);
    cout << find_max_sum(arr, dp, (int)arr.size()-1) << "\n";

    return 0;
}
