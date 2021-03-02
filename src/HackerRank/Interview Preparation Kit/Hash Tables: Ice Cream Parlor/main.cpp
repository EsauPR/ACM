/**
 * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_r=internal-search
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int find(vector<pair<int, int>> &flavors, int num) {
    int i = 0;
    int j = flavors.size() - 1;

    while (i <= j) {
        int middle = (i+j) / 2;

        if (flavors[middle].first == num) {
            return flavors[middle].second;
        }

        if (flavors[middle].first < num) {
            i = middle + 1;
        } else {
            j = middle -1;
        }
    }

    return -1;
}


int main() {
    int ncases = 0;
    int cochinito = 0;
    int n_flavors = 0;
    int flv = 0;

    cin >> ncases;

    while(ncases--) {
        cin >> cochinito;
        cin >> n_flavors;
        vector<pair<int, int>> flavors;

        for (int i = 0; i < n_flavors; i++) {
            cin >> flv;
            flavors.push_back(make_pair(flv, i+1));
        }

        sort(flavors.begin(), flavors.end());

        for (auto pii: flavors) {
            int first_idx = pii.second;
            int num = pii.first;
            int second_idx = find(flavors, cochinito - num);

            if (second_idx != -1 && first_idx != second_idx) {
                if (first_idx < second_idx) {
                    cout << first_idx << " " << second_idx << "\n";

                } else {
                    cout << second_idx << " " << first_idx << "\n";
                }

                break;
            }
        }
    }

    return 0;
}
