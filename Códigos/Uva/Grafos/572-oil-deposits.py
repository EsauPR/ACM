'''
    Problem: Oil Deposits
    Problem Number: 572
    Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=513
'''

import sys

GRAPH = []
MOVS = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1)]


def read_line():
    return sys.stdin.readline().strip()


def valid_plot(m, n, i, j):
    if( i < 0 or j < 0 or i >= m or j >= n):
        return 0
    return 1


def bfs(m, n, i, j):
    for k_i, k_j in MOVS:
        next_i = i + k_i;
        next_j = j + k_j;

        if valid_plot(m, n, next_i, next_j) and GRAPH[next_i][next_j] == '@':
            GRAPH[next_i][next_j] = '*'
            bfs(m, n, next_i, next_j)


def main():
    global GRAPH

    while True:
        GRAPH = []
        m, n = [int(x) for x in read_line().split()]

        if m == 0  and n == 0:
            return

        for i in range(m):
            GRAPH.append(list(read_line()))

        count = 0
        for i in range(m):
            for j in range(n):
                if GRAPH[int(i)][int(j)] == '@':
                    count += 1
                    GRAPH[int(i)][int(j)] = '*'
                    bfs(m, n, int(i), int(j))

        print(count)


if __name__ == '__main__':
    main()
