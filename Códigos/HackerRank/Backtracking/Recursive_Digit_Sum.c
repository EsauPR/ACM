/**
 * Problem: Recursive Digit Sum
 * url: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

int super_digit(long int p) {
	char p_char[MAX];
	int sum = 0;
	
	sprintf(p_char, "%ld", p);
	
	if (strlen(p_char) == 1)
		return atoi(p_char);
	
	for (int i=0; i<strlen(p_char); i++) {
		sum += p_char[i] - '0';
	}
	
	return super_digit(sum);
}


int main(int argc, char const *argv[]) {
	char digit;
	int k;
	long int p;
	
	while(scanf("%c", &digit), digit != ' ') {
		p += digit-'0';
	}
	
	scanf("%d", &k);
	
	p *= k;
	
	printf("%ld", super_digit(p));
	
	return 0;
}

