#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100002
#define pii pair<int, int>
#define vdii vector<pair<int, pair<int, int> > >

int parent[MAX];

void reset_parents(int total_nodes) {
    for (int i = 0; i <= total_nodes; i++) {
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

int count_parents(int total_nodes) {
    int count = 0;

    for (int i = 1; i <= total_nodes; i++) {
        if (parent[i] == i) {
            count ++;
        }
    }

    return count;
}

pii minimun_spanning_tree(int total_nodes, vdii nodes_distances, int max_cost) {
    reset_parents(total_nodes);
    int cost = 0;
    int extra_airports = 0;
    for (vdii:: iterator it = nodes_distances.begin(); it != nodes_distances.end(); it++) {
        int a = it->second.first;
        int b = it->second.second;
        if (find_parent(a) != find_parent(b)) {
            union_set(a, b);
            if (it->first < max_cost) {
                cost += it->first;
            } else {
                cost += max_cost;
                extra_airports ++;
            }
        }
    }
    return make_pair(cost, extra_airports);
}


int main(int argc, char const *argv[]) {
    int ncases, nroads, nlocations, airport_cost;

    scanf("%d", &ncases);

    for (int icase = 1; icase <= ncases; icase++) {
        scanf("%d %d %d", &nlocations, &nroads, &airport_cost);

        vdii roads;
        for (int i = 0; i < nroads; ++i) {
            int location_i, location_j, road_cost;
            scanf("%d %d %d", &location_i, &location_j, &road_cost);
            roads.push_back(make_pair(road_cost, make_pair(location_i, location_j)));
        }

        sort(roads.begin(), roads.end());

        pii result = minimun_spanning_tree(nlocations, roads, airport_cost);
        int components = count_parents(nlocations);
        int cost = result.first + components * airport_cost;
        printf("Case #%d: %d %d\n", icase, cost , result.second + components);
    }

    return 0;
}
