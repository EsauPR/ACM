#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int ncases;
    int px, py, qx, qy, rx, ry;

    cin >> ncases;

    for (int i = 0; i < ncases; ++i) {
        cin >> px >> py >> qx >> qy;

        rx = px - qx;
        ry = py - qy;

        rx = qx - rx;
        ry = qy - ry;

        cout << rx << " " << ry << endl;

    }
    return 0;
}
