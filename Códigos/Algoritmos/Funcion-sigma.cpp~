/*
	Denota la suma de todos los divisores propios e impropios de un número n;
	Por ejemplo los divisores de 12 son:
	1 2 3 4 6 12,  su suma es 28
	
	El divisor impropio de un numero es si mismo
	
*/
#include <stdio.h>
#include <bitset>
#include <vector>
#define MAX 47000
#include <math.h>
using namespace std;

bitset<MAX> criba;
vector<int> primos;


void sieve()
{
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

int sigma(int num)
{
	int sol = 1, ex, n = num;
	for(int i=0; i<primos.size() && primos[i]*primos[i] <= n ; i++){
		if(n%primos[i] == 0){
			ex = 1;
			while(n%primos[i]==0){
				ex++; n/=primos[i];
			}
			sol *= ( pow( primos[i], ex ) - 1) / ( primos[i] - 1 );
		}
	}
	if(n>1)
		sol *= ( pow( n, 2 ) - 1) / ( n - 1 );
	
	return sol; // sol - num , si se quiere solo la suma de los divisores propios
}

int main()
{
	sieve();
	
	for(int i=1; i<21; i++)
		printf("%d -> %d\n",i, sigma(i));
	
	return 0;
}

