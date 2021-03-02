/*
 * Tower of Hanoi
 * https://cses.fi/problemset/task/2165
 */


#include <iostream>
#include <string>
#include <map>

using namespace std;

int c_map[8] = {0,0,0,0,0,0,0,0};
map<string, int> sols;

void gen_string(string text, string gen="") {
    if (text.size() == gen.size()) {
        // cout << gen << "\n";
        sols[gen] = 1;
        return;
    }

    for (uint i = 0; text[i] != '\0'; i++) {
        if (c_map[i] == 1) continue;

        string tmp = gen + text[i];
        c_map[i] = 1;
        gen_string(text, tmp);
        c_map[i] = 0;
    }
}


int main(int argc, char const *argv[]) {
    string text;
    cin >> text;

    gen_string(text);
    cout << sols.size() << "\n";
    for (map<string, int>::iterator i = sols.begin(); i != sols.end(); ++i) {
        cout << i->first << "\n";
    }

    return 0;
}
