//10783 - Odd Sum
#include <stdio.h>

int main()
{
	int nc, a,b;
	scanf("%d", &nc);
	int res;
	while(nc--)
	{
		res = 0;
		scanf("%d %d", &a,&b);
		if(a%2==0) a++;
		if(b%2==0) b--;
		if(a!=1 && a!=0) a = (a-1)/2 - 1;
		else
		{ 
			a=0; res = 1;
		}
		b = (b-1)/2;
		res += (b*b+2*b)-(a*a+2*a);
		if(a==0) res++;
		printf("%d %d %d\n", a,b,res);
	}
	return 0;
}
