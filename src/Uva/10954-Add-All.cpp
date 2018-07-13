// 10954 Add All
#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<long long int> cola;	

void clean()
{
	while(!cola.empty())
		cola.pop();
}

int main()
{
	long long int tmp,a,b, total;
	int nc;
	while( scanf("%d", &nc), nc)
	{
		clean();
		total=0;
		while(nc--)
		{
			scanf("%lld", &tmp);
			cola.push(-tmp);
		}
		
		while(cola.size()>1)
		{
			a=cola.top(); cola.pop();
			b=cola.top(), cola.pop();
			cola.push(a+b);
			total += a+b;
		}
		printf("%lld\n", -total);
	}
	
	return 0;
}
