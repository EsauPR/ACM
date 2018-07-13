/**
 * Problem: Hardwood Species
 * Problem ID: 10226
 * url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1167&mosmsg=Submission+received+with+ID+19561883
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>

#define MAX_SIZE 100

using namespace std;

int main(int argc, char const *argv[]) {
	int ncases;
	char line[MAX_SIZE];

	scanf("%d\n", &ncases);
	while(ncases --) {
		map<string, int> trees;
		int total = 0;

		while(fgets(line, MAX_SIZE, stdin)) {
			if (line[0] == '\n')  break;
			
			total ++;
			line[strlen(line)-1] = '\0';
			
			if (trees.find(string(line)) != trees.end()) {
				trees[string(line)] ++;
			} else {
				trees[string(line)] = 1;
			}
		}

		for(map<string, int>::iterator it = trees.begin(); it != trees.end(); it++) {
			printf("%s %.4f\n",it->first.c_str(), (float)(it->second * 100) / total);
		}

		if (ncases) puts("");
	}

	return 0;
}