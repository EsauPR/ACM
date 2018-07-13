#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    Problem: CD
    url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565
"""

import sys


def read_line():
	return sys.stdin.readline().strip()


def solve(tape_length, songs, nsongs):
	begin = (1 << nsongs) -1
	max_total = 0
	solution = 0

	while begin:
		total = 0
		count = 0
		selection = begin;

		while selection:
			if selection & 1:
				total += songs[count]
			count += 1
			selection = selection >> 1

		if max_total < total and total <= tape_length:
			max_total = total
			solution = begin
		
		if max_total == tape_length:
			break

		begin -= 1

	count = 0

	str_sol = ''
	while solution:
		if solution & 1:
			str_sol = "%s %d" % (str_sol, songs[count])
		solution = solution >> 1
		count += 1

	print("%s sum:%d" % (str_sol[1:], max_total))


def main():
	while True:
		values = read_line().split()
		if not values:
			break	
		tape_length = int(values[0])
		nsongs = int(values[1])
		songs = [int(x) for x in values[2:]]
		solve(tape_length, songs, nsongs)


if __name__ == '__main__':
	main()