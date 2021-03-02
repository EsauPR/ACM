#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nelems, tmp;
    vector<int> arr;

    cin >> nelems;

    for (int i = 0; i < nelems; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    int count = 0;
    for (int i = 0; i < nelems; i++) {
        for (int j = 0; j < nelems - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                count ++;
            }
        }
    }

    cout << "Array is sorted in " << count << " swaps.\n";
    cout << "First Element: " << arr[0] << "\n";
    cout << "Last Element: " << arr[arr.size()-1] << "\n";

    return 0;
}
