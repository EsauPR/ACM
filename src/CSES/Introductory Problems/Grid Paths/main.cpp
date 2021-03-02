/**
 * Grid Paths
 * https://cses.fi/problemset/task/1625
 **/

#include <iostream>
#include <string>

using namespace std;

#define VISITED 1
#define UNVISITED 0

int grid[7][7];
int count = 0;
string path;

bool valid_mov(int px, int py) {
    if (px >=0 && px < 7 && py >= 0 && py < 7 && grid[px][py] == UNVISITED) {
        return true;
    }

    return false;
}


void solve(int px=0, int py=0, int pos=0) {
    if (px==6 && py ==0) {
        if (pos == 48) {
            count ++;
        }
        return;
    }

    grid[px][py] = VISITED;

    char move = path[pos];

    if (move == '?' || move == 'U') {
        if (valid_mov(px - 1, py) && !(!valid_mov(px - 2, py) && valid_mov(px - 1, py - 1) && valid_mov(px - 1, py + 1))) {
            solve( px - 1, py, pos + 1);
        }
    }

    if (move == '?' || move == 'D') {
        if (valid_mov(px + 1, py) && !(!valid_mov(px + 2, py) && valid_mov(px + 1, py - 1) && valid_mov(px + 1, py + 1))) {
            solve( px + 1, py, pos + 1);
        }
    }

    if (move == '?' || move == 'R') {
        if (valid_mov(px, py + 1) && !(!valid_mov(px, py + 2) && valid_mov(px + 1, py + 1) && valid_mov(px - 1, py + 1))) {
            solve( px, py + 1, pos + 1);
        }
    }

    if (move == '?' || move == 'L') {
        if (valid_mov(px, py - 1) && !(!valid_mov(px, py - 2) && valid_mov(px + 1, py - 1) && valid_mov(px - 1, py - 1))) {
            solve( px, py -1, pos + 1);
        }
    }

    grid[px][py] = UNVISITED;
}


int main() {

    cin >> path;

    solve();

    cout << count << "\n";

    return 0;
}
