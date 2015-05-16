//543 y 686
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 33000

int v[MAX];
vector <int> primos;
int n;

int bus(int num, int pos, int f)
{
	if(pos>f) return 0;	
		int m = (pos+f)/2;
		if(primos[m]+num ==n)
			return primos[m];
		if(primos[m]+num > n)
			return bus(num, pos, m-1);
		else
			return bus(num, m+1, f);
}

void sieve()
{
	primos.clear();
	primos.push_back(1);
	for(int i=2;i<MAX;i++)
		if(v[i]==0)
		{
			
			for(int j=i+i;j<MAX;j+=i)
			{
				v[j]=1;
			}
		}
	for(int i=2;i<MAX;i++)
		if(v[i]==0)
			primos.push_back(i);
}
main()
{
	sieve();
	int b=0;
	while(scanf("%d", &n),n)	
	{
		b=0;
		for(int i=1; i<primos.size(); i++)
		{
			int tmp = bus(primos[i], i, primos.size());
			
			if(tmp){
	//			printf("%d = %d + %d\n",n, primos[i], tmp);
				b++;
//				break;
			}
		}
//		if(b==0)
//			printf("Goldbach's conjecture is wrong.\n");
		printf("%d\n", b);

	}	
}
