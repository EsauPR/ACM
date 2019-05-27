/**
 * Problem: Recursive Digit Sum
 * url: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

#define MAX_LENGTH 3000

using namespace std;

char solution[MAX_LENGTH];
char passwords[20][MAX_LENGTH];
int npass;

map<string, bool> memo;

int begin_with(char * attemp, char * word) {
	if (strlen(word) > strlen(attemp)) return 0;

	for (int i = 0; i < strlen(word); i++) {
		if(word[i] != attemp[i]) {
			return 0;
		}
	}

	return 1;
}

int solve(char * attemp) {
	if (attemp[0] == '\0')
		return 1;

	if (memo[string(attemp)]) return 0;

	for (int i = 0; i < npass; i++) {
		if (begin_with(attemp, passwords[i])) {
			memo[string(attemp)] = true;
			if (solve(attemp + strlen(passwords[i]))) {
				char tmp[MAX_LENGTH];
				tmp[0] = '\0';
				strcpy(tmp, solution);
				strcpy(solution, passwords[i]);
				strcat(solution, " ");
				strcat(solution, tmp);
				return 1;
			}
		}
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	int ncases;
	char attemp[MAX_LENGTH];

	scanf("%d", &ncases);

	while(ncases--) {
		scanf("%d", &npass);

		for (int i = 0; i < npass; i++) {
			scanf("%s", passwords[i]);
		}

		scanf("%s", attemp);

		solution[0] = '\0';
		memo.clear();

		if (solve(attemp)) {
			solution[strlen(solution) - 1] = '\0';
			printf("%s\n", solution);
		} else {
			puts("WRONG PASSWORD");
		}
	}

	return 0;
}
