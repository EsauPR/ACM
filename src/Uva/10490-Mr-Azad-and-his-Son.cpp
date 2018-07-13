// 10490 - Mr. Azad and his Son!!!!!
#include <stdio.h>
#include <vector>
#include<bitset>
#include <math.h>
#define MAX 47000
using namespace std;

bitset<MAX> criba;
vector<int> primos;

void llenacriba(){
	criba.set();
	criba.reset(0);
	criba.reset(1);
	for(int i=2; i<MAX; i++)
		if(criba[i]){
			primos.push_back(i);
			for(int j=i<<1; j<MAX; j+=i)
				criba.reset(j);
		}
}

bool isprime(long long int num)
{
	int tmp=num;
	for(int i=0; i<primos.size() && primos[i]*primos[i] <= tmp; i++ )
	{
		if(tmp%primos[i]==0)
			return false;
	}
	return true;
}

long long int f(long long int k)
{
	return pow(2,(k-1))*(pow(2,k)-1);
}

int main()
{
	llenacriba();
	long long int num;
	
	while(scanf("%lld", &num),num)
	{
		if(isprime( (1<<num)-1) )
					printf("Perfect: %lld!\n",f(num));
		else{
			if(isprime(num))
				printf("Given number is prime. But, NO perfect number is available.\n");
			else printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}
	return 0;
}
