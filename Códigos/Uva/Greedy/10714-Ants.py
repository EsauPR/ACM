#!/usr/bin/env python
# -*- coding: utf-8 -*-

#
# Problem: Ants
# Problem ID: 10714
# url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1655
#

import sys

def get_line():
    return sys.stdin.readline().strip()

def main():
    ncases = int(get_line())

    while ncases:
        length, total_ants = list(map(int, get_line().split()))
        earliest_time = latest_time = 0

        distances = list(map(int, get_line().split()))
        for distance in distances:
            earliest_time = max(earliest_time, min(distance, length - distance))
            latest_time = max(latest_time, max(distance, length - distance))

        print("%d %d" % (earliest_time, latest_time))
        ncases -= 1

if __name__ == '__main__':
    main()
