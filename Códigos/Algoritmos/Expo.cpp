#include <stdio.h>
#include <string.h>
char m;
#define swap(a,b) m=(a), a=(b), b=m;

int modpow(int x, int n, int p)
{
	if(n==0)
		return 1;
	int t = modpow(x, n/2, p);
	if(n%1)
		return ((t%p)*(t%p))%p;
	return ((((t%p)*(t%p))%p)* (x%p))%p;
		
}

char vec[10005];

void reverse()
{
	int i=0; 
	int j=strlen(vec)-1;
	while(i<j)
		swap(vec[i++], vec[j--]);
	
}

int main()
{
	
	int n;

	scanf("%d", &n);
	
	while(n--)
	{
		reverse();
		
	}
	
	return 0;
}
