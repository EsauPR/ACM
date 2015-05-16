#include <stdio.h>

int vec[100];

int main()
{
	int nc,n;
	int t=1;
	scanf("%d", &nc);
	while(nc--){
		int max=0, min=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &vec[i]);
		for(int i=0; i<n-1; i++)
			if(vec[i]>vec[i+1])
				min++;
			else if(vec[i] < vec[i+1])
				max++;
		printf("Case %d: %d %d\n",t++,max,min);
	}
	return 0;
}
