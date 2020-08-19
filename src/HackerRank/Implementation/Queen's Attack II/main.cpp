/*
    https://www.hackerrank.com/challenges/queens-attack-2/problem

    To do:
        - Validate obstacles on the same row col o diag
*/

#include <iostream>
#include <map>
#include <vector>
// #include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define Coord pair<int, int>
#define Obs map<Coord, bool>


bool find_obs(Obs obs, int rt, int ct) {
    Coord o = make_pair(rt, ct);
    if (obs.find(o) == obs.end() ) {
        return false;
    }
    return true;
}


int get_x(int cq, int rq, int y, int m) {
    if (m == 1) {
        return y - rq + cq;
    }

    return rq + cq - y;
}

int get_y(int cq, int rq, int x, int m) {
    if (m == 1) {
        return x - cq + rq;
    }

    return rq + cq - x;
}



int main(int argc, char const *argv[]) {
    int n, nobs;
    int r_q, c_q;
    int rt, ct;
    Obs obs;

    cin >> n >> nobs;
    cin >> r_q >> c_q;

    int count = n * 2 - 2; // Only up, down, right, left

    // Diagonal => /
    int x1, y1, x2, y2;

    x1 = 1;
    y1 = get_y(c_q, r_q, x1, 1);
    if (y1 < 1) {
        y1 = 1;
        x1 = get_x(c_q, r_q, y1, 1);
    }

    x2 = n;
    y2 = get_y(c_q, r_q, x2, 1);
    if (y2 > n) {
        y2 = n;
        x2 = get_x(c_q, r_q, y2, 1);
    }

    count += abs(x2 - x1);

    // Diagonal => \

    x1 = 1;
    y1 = get_y(c_q, r_q, x1, -1);
    if (y1 > n) {
        y1 = n;
        x1 = get_x(c_q, r_q, y1, -1);
    }

    x2 = n;
    y2 = get_y(c_q, r_q, x2, -1);
    if (y2 < 1) {
        y2 = 1;
        x2 = get_x(c_q, r_q, y2, -1);
    }


    count += abs(x2 - x1);

    int obs_c_r = -1, obs_r_r = -1;
    int obs_c_l = -1, obs_r_l = -1;
    int obs_c_u = -1, obs_r_u = -1;
    int obs_c_d = -1, obs_r_d = -1;
    int obs_c_ru = -1, obs_r_ru = -1;
    int obs_c_lu = -1, obs_r_lu = -1;
    int obs_c_rd = -1, obs_r_rd = -1;
    int obs_c_ld = -1, obs_r_ld = -1;

    //  Select at the most 8 obstacles for que queen
    for (int i = 0; i <  nobs; i++) {
        int obs_r, obs_c;
        cin >> obs_r >> obs_c;

        if (obs_r == r_q) { // same row
            if (obs_c < c_q) { // to the left
                if (obs_c_l == -1 || obs_c > obs_c_l) {
                    obs_c_l = obs_c;
                    obs_r_l = obs_r;
                }
            } else { // to the rigth
                if (obs_c_r == -1 || obs_c < obs_c_r) {
                    obs_c_r = obs_c;
                    obs_r_r = obs_r;
                }
            }
        } else if (obs_c == c_q) { // same column
            if (obs_r > r_q) { // up
                if (obs_r_u == -1 || obs_r < obs_r_u) {
                    obs_c_u = obs_c;
                    obs_r_u = obs_r;
                }
            } else { //  down
                if (obs_r_d == -1 || obs_r > obs_r_d) {
                    obs_c_d = obs_c;
                    obs_r_d = obs_r;
                }
            }
        } else if (abs(r_q - obs_r) == abs(c_q - obs_c)) { // diagonal / with the queen
            if (obs_r < r_q && obs_c < c_q) { // left down
                if (obs_r_ld == -1 || obs_r > obs_r_ld) {
                    obs_c_ld = obs_c;
                    obs_r_ld = obs_r;
                }
            } else if (obs_r > r_q && obs_c > c_q) { // rigth up
                if (obs_r_ru == -1 || obs_r < obs_r_ru) {
                    obs_c_ru = obs_c;
                    obs_r_ru = obs_r;
                }
            } else if (obs_r < r_q && obs_c > c_q) { // rigth down
                if (obs_r_rd == -1 || obs_r > obs_r_rd) {
                    obs_c_rd = obs_c;
                    obs_r_rd = obs_r;
                }
            } else if (obs_r > r_q && obs_c < c_q) { // left up
                if (obs_r_lu == -1 || obs_r < obs_r_lu) {
                    obs_c_lu = obs_c;
                    obs_r_lu = obs_r;
                }
            }
        }

    }


    if (obs_r_u != -1) { // up
        count -= n - obs_r_u + 1;
    }
    if (obs_r_d != -1) { // down
        count -= obs_r_d;
    }
    if (obs_c_r != -1) { // rigth
        count -= n - obs_c_r + 1;
    }
    if (obs_c_l != -1) { // left
        count -= obs_c_l;
    }
    if (obs_r_ru != -1) { // rigth up
        count -= min(n - obs_r_ru, n - obs_c_ru) + 1;
    }
    if (obs_r_rd != -1) { // rigth down
        count -= min(n - obs_c_rd + 1, obs_r_rd);
    }
    if (obs_r_lu != -1) { // left up
        count -= min(n - obs_r_lu + 1, obs_c_lu);
    }
    if (obs_r_ld != -1) { //  left down
        count -= min(obs_r_ld, obs_c_ld);
    }

    cout << count << endl;

    return 0;
}
