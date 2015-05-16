#include <stdio.h>


int exp(int a, int  b, int c)
{
	if(b==1) return a%c;
	if(b==2) return ( (a%c) * (a%c)) %c;
	
	int res = exp(a,b/2,c);
	res = ((res%c) * (res%c))%c;
	if(b&1)
		res = ((res%c) * (a%c))%c;
	return res;
}

int main()
{
	int a,b,c,n;
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &a,&b,&c);
		printf("%d\n", exp(a,b,c));
	}
	
	return 0;
}
