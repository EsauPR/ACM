/*
    https://www.hackerrank.com/challenges/grading/problem
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    int ncases;
    int grade;

    cin >> ncases;

    for (int i = 0; i < ncases; i++) {
        cin >> grade;
        if (grade < 38) {
            cout << grade << endl;
            continue;
        }

        bool ok = true;
        for(int j = 1; j < 3; j++) {
            if ((grade + j) % 5 == 0) {
                ok = false;
                cout << grade + j << endl;
                break;
            }
        }

        if (ok) {
            cout << grade << endl;
        }

    }

    return 0;
}
