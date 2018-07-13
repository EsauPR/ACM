#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys


def read_line():
    return sys.stdin.readline().strip()


def main():
    N, D  = [int(x) for x in read_line().split()]
    array = read_line().split()
    rotations = read_line().split()

    last_rotation = 0
    for rotation in rotations:
        last_rotation += int(rotation)

    if last_rotation < 0:
        position = (last_rotation * -1) % N
    else:
        position = N - (last_rotation % N)

    for i in range(N):
        if i == N - 1:
            print(array[(position + i) % N])
        else:
            sys.stdout.write((array[(position + i) % N]) + ' ')

if __name__ == '__main__':
    main()
