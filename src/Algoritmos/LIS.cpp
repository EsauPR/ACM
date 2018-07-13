/**
 *	The longest increasing subsequence problem is to find a subsequence of a given sequence 
 *	in which the subsequence's elements are in sorted order, lowest to highest, and in which 
 *	the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.
 */

/* 
in
	4 -1 5 8 2 3 12 7 9 10
out
	6 => -1 2 3 7 9 10
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "algorithm"

using namespace std;

#define MAX 100000

int A[MAX];
int LIS[MAX];
int PATH[MAX];

void printPath(int pos ) 
{
	if (pos == -1) {
		return;
	}

	printPath( PATH[pos] );
	printf("%d\n", A[pos] );
}

int lis_cuadratic(int size ) 
{
	/*
		LIS(i) = 1 + max[j=1 to i-1]( LIS(j) ) if A[j] > A[i]
		LIS(i) = 1 if no exist A[j] > A[i] for j=1 to i-1
	 */
	int maxi=0, pos = 0;

	for (int i = 0; i < size; i++) {
		
		LIS[i] = 1;
		PATH[i] = -1;

		for (int j = 0; j < i; j++) {
			if ( A[i] > A [j] ){
				if (LIS[j] >= LIS[i]) {
					LIS[i] = LIS[j] + 1;
					PATH[i] = j;
				}
			}
		}

		if (LIS[i] >= maxi) {
			maxi = LIS[i];
			pos = i;
		}
	}

	printf("%d\n-\n", maxi);
	printPath(pos);
}

int ceilIndex(int l, int r, int key) {
	while (r-l > 1) {
		int m = l + (r-l)/2;
		
		if (A[LIS[m]] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

void lis_nlogn(int size) 
{
	/*
		LIS(i) = index of the minimum value of the last value of increasing subsequence of length i
		Example 
		A = [ 3, 4, -1, 1 ]

		For LIS(2) :
			sub1 = [3, 4] sub2 = [-1, 1]
			LIST(2) = indexof(1) = 3
		Beacause is better to have a subsequence of length 3 that finish with 1 instead of finish with 4
	*/

	int maxi = 1;

	LIS[1] = 0;
	PATH[0] = -1;

	for (int i = 1; i < size; i++) {
		PATH[i] = -1;
		if ( A[i] > A[LIS[maxi]] ) { // A[i] > minimum value of the last value of increasing subsequence of length max
			LIS[++maxi] = i;
			PATH[i] = LIS[maxi-1];
		}
		else if ( A[i] < A[LIS[1]] ) {
			LIS[1] = i;
		}
		else {
			int index = ceilIndex(0,maxi, A[i]);
			LIS[ index ] = i;
			PATH[i] = LIS[index-1];
		}
	}
	
	printf("%d\n-\n", maxi);
	printPath(LIS[maxi]);
}

int main(int argc, char const *argv[])
{
	int num, count = 0;

	while (scanf("%d", &num) != EOF) {
		if (num != A[count-1]) {
			A[count++] = num;
		}
	}

	lis_cuadratic(count);
	puts("");
	lis_nlogn(count);

	return 0;
}

