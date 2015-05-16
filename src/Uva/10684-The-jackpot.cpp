//10684 - The jackpot
#include <algorithm>
#include <stdio.h>
using namespace std;


int main()
{

	int n, num;
	
	while(scanf("%d",&n),n)	{

		int maxi=0, sum=0;		
		for(int i=0; i<n; i++){
			scanf("%d", &num);
			sum += num;
			maxi = max(maxi, sum);
			sum =  max(sum,0);
		}
		if(maxi>0)
			printf("The maximum winning streak is %d.\n", maxi);
		else puts("Losing streak.");
	}	
	
	return 0;
}
