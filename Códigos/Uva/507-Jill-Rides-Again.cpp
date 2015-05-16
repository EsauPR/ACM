#include <stdio.h>
#include <algorithm>
using namespace std;

long long int a[20001],p[20001],s[20001];

void llena(int n)
{
	for(int i=1; i<=n; i++)
		p[i] = i;
}

int sol(int num)
{
	if(p[num] == num)
		return 0;
	return 1 + sol(p[num]);
}

int main()
{
	int nc, num,nm;	
	long long int sum;
	long long int maxi;
	int ind=0;
	int ind2=0;
	scanf("%d", &nc);
	for(int k=1; k<=nc; k++)
	{
		scanf("%d", &nm);
		for(int i=1; i<nm; i++)
			scanf("%lld", &a[i]);
		
		llena(nm);
		
		sum=0;
		maxi = a[1];
		ind2=1;
		for(int i=1; i<nm; i++)
		{
			sum += a[i];
			p[i] = i-1;
			if(maxi<=sum)
			{
				ind = i;
				maxi = sum;
			}
			if(sum<0)
			{
				sum=0;
				ind2=i;
				p[i] = i;
			}
			s[i]=sum;
		}
		/*
		for(int i=1; i<nm; i++)
		
			printf("%lld ",a[i]);
		puts("");
		for(int i=1; i<nm; i++)
			printf("%lld ",p[i]);
		puts("\n");
		*/
		int dis=0;
		int tmp;
		for(int i=1; i<nm; i++)
		{
			if(s[i]==maxi)
			{
				tmp = sol(i);
				if(tmp>dis)
				{
					ind = i;
					dis = tmp;
				}
			}
		}
		ind2 = sol(ind);
		if(maxi<0)
			printf("Route %d has no nice parts\n",k);
		else	printf("The nicest part of route %d is between stops %d and %d\n",k,ind-ind2+1,ind+1);
//		puts("\n-------");
	}
	
	return 0;
}
