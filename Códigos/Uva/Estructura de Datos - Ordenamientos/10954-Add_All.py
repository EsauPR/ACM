#!/usr/bin/env python
# -*- coding: utf-8 -*-

#
# Problem: Add All
# Problem ID: 10954
# url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1895&mosmsg=Submission+received+with+ID+19561573
#

import sys
import heapq


def getLine():
    return sys.stdin.readline().strip()

while True:
    list_size = int(getLine())
    if list_size == 0:
        break

    ls = map(int, getLine().split())

    queue = []
    for num in ls:
        heapq.heappush(queue, num)

    cost = 0
    while len(queue) > 1:
        a = heapq.heappop(queue)
        b = heapq.heappop(queue)
        heapq.heappush(queue, a + b)
        cost += a + b

    print(cost)
