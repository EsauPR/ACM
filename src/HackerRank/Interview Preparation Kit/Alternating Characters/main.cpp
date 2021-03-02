#include <iostream>
#include <string>

using namespace std;


int main() {
    int ncases = 0;
    string str;

    cin >> ncases;

    while (ncases --) {
        cin >> str;

        int count = 0;
        char prev = 'C';

        for (auto item : str) {
            if (item != prev) {
                prev = item;
            } else {
                count ++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
