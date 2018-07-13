#include <stdio.h>

int gcd(int a, int b, int c)
{
	int div=2;
	int mcd=1;
	while(div <= a && div <= b && div <= c && a!=1 && b!=1 && c!= 1)
	{
		while(a%div == 0 && b%div == 0 && c%div==0)
		{
			a/=div;
			b/=div;
			c/=div;
			mcd *= div;
		}
		div++; 
	}
	return mcd;
}

int main()
{
	int a,  b,  c;
	
	scanf("%d %d %d", &a, &b, &c);
	printf("GCD %d %d\n", gcd(a,b,c), 0%2);
	
	return 0;
}
