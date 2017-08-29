#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    Problem: The Power Sum
    url: https://www.hackerrank.com/challenges/the-power-sum
"""

import sys


def read_line():
	return sys.stdin.readline().strip()


def power_sum(X, N, num):
    num_pow = pow(num, N)

    if num_pow == X:
        return 1
    if num_pow > X:
        return 0

    num += 1
    count = 0
    while pow(num, N) <= X:
        count += power_sum(X - num_pow, N, num)
        num += 1

    return count


def main():
    X = int(read_line())
    N = int(read_line())

    count = 0
    i = 1
    while pow(i, N) <= X:
        count += power_sum(X, N, i);
        i += 1

    print(count)


if __name__ == '__main__':
    main()

