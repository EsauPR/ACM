#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100000

int A[MAX];
int LIS[MAX];
int PATH[MAX];


vector<pair<int, pair<int, int>>> elephants;


void printPath(int pos ) {
    if (pos == -1) {
        return;
    }

    printPath( PATH[pos] );
    printf("%d\n", elephants[pos].second.second);
}

int ceilIndex(int l, int r, int key) {
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (elephants[LIS[m]].second.first >= key) {
            r = m;
        }
        else {
            l = m;
        }
    }

    return r;
}

void lis_nlogn(int size) {
    int maxi = 1;

    LIS[1] = 0;
    PATH[0] = -1;

    for (int i = 1; i < size; i++) {
        PATH[i] = -1;
        if (elephants[i].second.first > elephants[LIS[maxi]].second.first ) {
            LIS[++maxi] = i;
            PATH[i] = LIS[maxi-1];
        }
        else if ( elephants[i].second.first < elephants[LIS[1]].second.first ) {
            LIS[1] = i;
        }
        else {
            int index = ceilIndex(0, maxi, elephants[i].second.first);
            LIS[ index ] = i;
            PATH[i] = LIS[index-1];
        }
    }

    printf("%d\n", maxi);
    printPath(LIS[maxi]);
}


int main(int argc, char const *argv[]) {
    int weight, iq, pos = 1;

    while (scanf("%d %d", &weight, &iq) != EOF) {
        elephants.push_back(make_pair(-iq, make_pair(weight, pos++)));
    }

    sort(elephants.begin(), elephants.end());

    lis_nlogn(elephants.size());

    return 0;
}
