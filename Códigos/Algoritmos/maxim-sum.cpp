#include <stdio.h>
#include <algorithm>

using namespace;

int A[];
int SIZE;

int maxsum(  ) {
	best = 0, sum = 0;

	for (int i = 0; i < SIZE; i++) {
		sum = max(0, A[i] + sum);
		best = max(best, sum);
	}

	return best;

}


int main()
{
	
}
