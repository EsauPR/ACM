/*
    Problem: Oil Deposits
    Problem Number: 572
    Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=513
 */

#include <stdio.h>
#include <stdlib.h>

char graph[101][101];
int movs[16] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
int m, n;

int valid_plot(int i, int j) {
    if( i < 0 || j < 0 || i >= m || j >= n) {
        return 0;
    }
    return 1;
}

void bfs(int i, int j) {
    for (int k = 0; k < 16; k+=2) {
        int next_i = i + movs[k];
        int next_j = j + movs[k+1];

        if (valid_plot(next_i, next_j) && graph[next_i][next_j] == '@') {
            graph[next_i][next_j] = '*';
            bfs(next_i, next_j);
        }
    }
}

int main(int argc, char const *argv[]) {
    while (scanf("%d %d", &m, &n), m, n) {
        for (int i = 0; i < m; i++) {
            scanf("%s", graph[i]);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == '@') {
                    count ++;
                    graph[i][j] = '*';
                    bfs(i,j);
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}