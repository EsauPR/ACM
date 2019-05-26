#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001

int PARENTS[MAX];


int find_parent(int node) {
    if (PARENTS[node] == -1) return node;
    return PARENTS[node] = find_parent(PARENTS[node]);
}

void union_set(int node_a, int node_b) {
    PARENTS[find_parent(node_a)] = find_parent(node_b);
}

void reset_parents() {
    memset(PARENTS, -1, sizeof(PARENTS));
}


long kruskal(vector<pair<int, int>> roads, int ncities, int nroads, int clib, int croad) {
    long  nlib = ncities;
    long nbuilded_roads = 0;

    if (clib < croad) return clib * nlib;

    // printf("cities %d\n", ncities);

    reset_parents();

    for (int i = 0; i < nroads; i++) {
        if (find_parent(roads[i].first) != find_parent(roads[i].second)) {
            /*printf("parents %d %d\n", PARENTS[roads[i].first], PARENTS[roads[i].second]);
            printf("union %d %d\n", roads[i].first, roads[i].second);*/
            union_set(roads[i].first, roads[i].second);
            nlib --;
            nbuilded_roads ++;
        }
    }

    /*printf("nlib %ld\n", nlib);
    printf("nbuilded_roads %ld\n", nbuilded_roads);*/
    return nlib * clib + nbuilded_roads * croad;
}


int main(int argc, char const *argv[]) {
    int ncases;

    scanf("%d", &ncases);

    while(ncases--) {
        int ncities, nroads, clib, croad, u, v;
        scanf("%d %d %d %d", &ncities, &nroads, &clib, &croad);
        vector<pair<int, int>> roads;

        for (int i = 0; i < nroads; i++) {
            scanf("%d %d", &u, &v);
            roads.push_back(make_pair(u, v));
        }

        printf("%ld\n", kruskal(roads, ncities, nroads, clib, croad));
    }

    return 0;
}
