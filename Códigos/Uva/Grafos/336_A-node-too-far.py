#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" 
    Problem: A Node Too Far
    Problem number: 336
    url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=272
"""

import sys
from collections import defaultdict

mybuffer = None
graph = None
visited = None

def read_line():
	line = sys.stdin.readline().strip()
	if not line:
		return read_line()
	return line


def next_int():
    global mybuffer
    
    if not mybuffer:
        mybuffer = [ int(x) for x in read_line().split() ]
    
    value = mybuffer[0]
    mybuffer = mybuffer[1:]
    return value


def dfs(node):
    for v in graph[node]:
        if v not in visited or visited[node] + 1 < visited[v]:
            visited[v] = visited[node] + 1
            dfs(v)


def bfs(start):
    queue = [start]
    visited[start] = 0
    
    while queue:
        node = queue.pop(0)
        for v in graph[node]:
            if v not in visited:
                visited[v] = visited[node] + 1
                queue.append(v)


def main():
    global graph
    global visited
    
    ncase = 0
    
    while True:
        graph = defaultdict(list)
        
        connections = next_int()
           
        if not connections:
            break
        
        for i in range(connections):
            u, v = next_int(), next_int()
            graph[u].append(v)
            graph[v].append(u)
        
        while True:
            start = next_int()
            ttl = next_int()
            visited = {}
                        
            if start == 0 and ttl == 0:
                break
            
            #visited[start] = 0
            #dfs(start)
            bfs(start)

            total_nodes = len(graph.keys())
            total_visited = len(visited.keys())
            unreachable = 0            
            for value in visited.values():
                if value > ttl:
                    unreachable += 1
            
            unreachable += total_nodes - total_visited
            
            ncase += 1
            print("Case %d: %d nodes not reachable from node %d with TTL = %d." % (ncase, unreachable, start, ttl))
                
          

if __name__ == '__main__':
	main()
