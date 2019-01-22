/*
    Problem: 11631 - Dark roads
    Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2678
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<vector>
#include <algorithm>

using namespace std;

#define MAX 200001
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

int minimun_spanning_tree(int total_nodes, vdii nodes_distances) {
    reset_parents(total_nodes);
    int cost = 0;
    for (vdii:: iterator it = nodes_distances.begin(); it != nodes_distances.end(); it++) {
        int a = it->second.first;
        int b = it->second.second;
        if (find_parent(a) != find_parent(b)) {
            union_set(a, b);
            cost += it->first;
        }
    }

    return cost;
}

int main(int argc, char const *argv[]) {
    int total_nodes, total_paths;
    int node_x, node_y, distance;

    while(scanf("%d %d", &total_nodes, &total_paths), total_nodes && total_paths) {
        vdii nodes_distances;
        int total_distance = 0;
        for (int i = 0; i < total_paths; i++) {
            scanf("%d %d %d", &node_x, &node_y, &distance);
            nodes_distances.push_back(
                make_pair(
                    distance,
                    make_pair(node_x, node_y)
                )
            );
            total_distance += distance;
        }

        sort(nodes_distances.begin(), nodes_distances.end());

        printf("%d\n", total_distance - minimun_spanning_tree(total_nodes, nodes_distances));
    }

    return 0;
}
