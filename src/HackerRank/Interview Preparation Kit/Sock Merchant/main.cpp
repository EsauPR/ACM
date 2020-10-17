/*
    https://www.hackerrank.com/challenges/sock-merchant
*/

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, color;
    map<int, int> pairs;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> color;
        pairs[color]++;
    }

    int npairs = 0;

    map<int, int>::iterator it;

    for (it = pairs.begin(); it != pairs.end(); it++) {
        npairs += it->second / 2;
    }

    cout << npairs << endl;

    return 0;
}
