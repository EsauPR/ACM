#include <iostream>
#include <map>
#include <string>

using namespace std;


int count_diff(map<char, int> & hist1, map<char, int> & hist2) {
    int count = 0;

    for (auto & item : hist1) {
        if (hist2.find(item.first) != hist2.end()) {
            int diff = item.second - hist2[item.first];
            if (diff > 0) {
                count += diff;
            }
        } else {
            count += item.second;
        }
    }

    return count;
}


int main() {
    map<char, int> hist1;
    map<char, int> hist2;

    string str1, str2;

    cin >> str1 >> str2;

    for (auto item : str1) {
        hist1[item] ++;
    }

    for (auto item : str2) {
        hist2[item] ++;
    }

    cout << count_diff(hist1, hist2) + count_diff(hist2, hist1) << "\n";

    return 0;
}
