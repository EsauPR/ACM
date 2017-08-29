#!/usr/bin/env python
# -*- coding: utf-8 -*-

#
# Problem: Hardwoodd Species
# Problem ID: 10226
# url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167
#

import sys


def getLine():
    return sys.stdin.readline().strip()

ncases = int(getLine())
getLine()

while ncases:
    ncases -= 1
    total = 0
    trees = {}

    while True:
        tree = getLine()
        if tree == "":
            break
        trees[tree] = trees.get(tree, 0) + 1
        total += 1

    keys = list(trees.keys())
    keys.sort()

    for key in keys:
        print("%s %.4f" % (key, float(trees[key]) / total * 100))

    if ncases:
        print("")
