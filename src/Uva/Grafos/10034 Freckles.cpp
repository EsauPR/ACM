/*
    Problem: 10034 - Freckles
    Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=975&mosmsg=Submission+received+with+ID+22658092
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<vector>
#include <algorithm>

using namespace std;

#define MAX 100
#define vdii vector<pair<double, pair<int, int> > >

int parent[MAX];


void reset_parents() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
    }
}

int find_parent(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = find_parent(parent[a]);
}

void union_set(int a, int b) {
    parent[find_parent(a)] = find_parent(b);
}

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1- y2) * (y1- y2));
}

vdii compute_distances(int total_freckles, double * freckles_X, double *freckles_Y) {
    vdii freckles_distances;
    for (int i = 0; i < total_freckles - 1; ++i) {
        for (int j = i + 1; j < total_freckles; j++) {
            freckles_distances.push_back(
                make_pair(
                    distance(freckles_X[i], freckles_Y[i], freckles_X[j], freckles_Y[j]),
                    make_pair(i, j)
                )
            );
        }
    }

    return freckles_distances;
}

double minimun_spanning_tree(vdii freckles_distances) {
    reset_parents();
    double total_ink = 0.0;
    for (vdii:: iterator it = freckles_distances.begin(); it != freckles_distances.end(); it++) {
        int a = it->second.first;
        int b = it->second.second;
        if (find_parent(a) != find_parent(b)) {
            union_set(a, b);
            total_ink += it->first;
        }
    }

    return total_ink;
}

int main(int argc, char const *argv[]) {
    int ncases, total_freckles;
    double freckles_X[100], freckles_Y[100];

    scanf("%d", &ncases);

    while(ncases--) {
        scanf("%d", &total_freckles);

        for (int i = 0; i < total_freckles; i++) {
            scanf("%lf %lf", &freckles_X[i], &freckles_Y[i]);
        }

        vdii freckles_distances = compute_distances(
            total_freckles,
            freckles_X,
            freckles_Y
        );

        sort(freckles_distances.begin(), freckles_distances.end());

        if (ncases > 0) {
            printf("%.2lf\n\n", minimun_spanning_tree(freckles_distances));
        } else {
            printf("%.2lf\n", minimun_spanning_tree(freckles_distances));
        }
    }

    return 0;
}
