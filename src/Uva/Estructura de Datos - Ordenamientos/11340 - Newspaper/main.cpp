#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
    int ncases;
    cin >> ncases;

    while(ncases--) {
        map<char, int> cost_map;
        int cost;

        string line;

        int n_chars, cw, value;
        cin >> n_chars;

        for (int i = 0; i < n_chars; i++) {
            scanf("%c %d\n", &cw, &value);
            cost_map[cw] = value;
        }

        int n_lines;
        scanf("%d\n", &n_lines);

        while(n_lines--) {
            getline(cin, line);
            for (int i = 0; i < line.size(); ++i) {

            }
        }

    }


    return 0;
}
