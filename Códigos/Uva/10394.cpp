
//10394 - Twin Primes

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 20000000

int v[MAX];
vector <int> primos;
vector <int> yeah;

void sieve()
{
	primos.clear();
//	primos.push_back(1);
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

int main()
{
	sieve();
	
	int n;
		
	for(int i=0; i<primos.size()-1; i++)
		if(primos[i+1]-primos[i] == 2)
			yeah.push_back(primos[i]);
	
	while(scanf("%d", &n)!=EOF)
		printf("(%d, %d)\n", yeah[n-1], yeah[n-1]+2);
	
	//cout << primos.size() << endl;
	
	return 0;	
}
