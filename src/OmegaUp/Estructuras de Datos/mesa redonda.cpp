#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int children, jumps;

    cin >> children >> jumps;

    int index = 0;
    int turns = 0;
    vector<int> table(children);

    for(int i = 0; i < children; i++) {
        table[i] = i;
    }

    do {
        index = (index + jumps) % table.size();
        if (index == 0) break;
        table.erase(table.begin() + index);
        turns ++;
    } while (index != 0);

    cout << turns << endl;

    return 0;
}
