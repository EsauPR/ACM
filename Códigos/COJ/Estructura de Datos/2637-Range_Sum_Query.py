#!/usr/bin/env python
# -*- coding: utf-8 -*-

#
# Problem: Range Sum Query
# Problem ID: 2637
# url: http://coj.uci.cu/24h/problem.xhtml?pid=2637
#

import sys


def getLine():
    return sys.stdin.readline().strip()

ncases = int(getLine())

while ncases:
    ncases -= 1

    getLine()
    nelements, nqueries = map(int, getLine().split())

    ls = map(int, getLine().split())
    for i in range(1, nelements):
        ls[i] += ls[i-1]

    for k in range(nqueries):
        i, j = map(int, getLine().split())
        print ls[j] if i == 0 else ls[j] - ls[i-1]

    if ncases:
        print
