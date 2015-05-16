#include <stdio.h>

long long int vec[50];
long long int nchi, p;

bool fun(int pos, long long int sum)
{
	if(sum==p) return true;
	if(sum>p) return false;
	if(pos<nchi)
	{
		return ( fun(pos+1,sum) == true || fun(pos+1,sum+vec[pos]) == true )? true:false;
	}
	return false;
}

int main()
{

	
	
	while( scanf("%lld %lld", &nchi,&p)!=EOF)
	{
		for(int i=0; i<nchi; i++)
			scanf("%lld", &vec[i]);
			
		if(fun(0,0))
			puts("YES");
		else puts("NO");
		
	}
	
	return 0;
}
