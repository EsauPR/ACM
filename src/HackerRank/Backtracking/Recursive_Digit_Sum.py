#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" 
    Problem: Recursive Digit Sum
    url: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
"""

import sys


def read_character():
	return sys.stdin.read(1)
	

def read_line():
	return sys.stdin.readline().strip()
	

def super_digit(p):
	if len(str(p)) == 1:
		return p
	
	sum = 0
	for digit in str(p):
		sum += int(digit)
	
	return super_digit(sum)
		


def main():
	sum = 0
	
	while(True):
		digit = read_character()
		if digit == ' ':
			break
		sum += int(digit)
	
	k = int(read_line())
	sum *= k
	
	print(super_digit(sum))


if __name__ == '__main__':
    main()

