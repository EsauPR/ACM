/*
	Denota la cantidad números m menores a n tal que n y m son primos relativos o coprimos
	Por ejemplo 12 es primo relativo con los siguientes números
	1 5 7 11
*/

#include <stdio.h>
#include <vector>
#include <bitset>
#define MAXPRIME 47000
using namespace std;

bitset <MAXPRIME> criba;
vector <int> primos;
int phi[MAXPRIME];

void sieve() // phi de euler precalculados para valores dentro de la criba
{
    criba.set();
    criba[0]=0;
    criba[1]=0;
    for(int i=0;i<MAXPRIME;i++)
        phi[i]=i;
    for(int i=2;i<MAXPRIME;i++)
    {
        if(criba[i])
        {
            primos.push_back(i);
            phi[i]=i-1;
            for(int j=i<<1;j<MAXPRIME;j+=i)
            {
                criba[j]=0;
                phi[j]/=i;
                phi[j]*=i-1;
            }   
        }
    }
}

int funcion_phi(int num) // phi de euler de un número n
{
	int sol = num;
	for(int i=0; i<primos.size() && primos[i]*primos[i]<=num; i++)
		if(num%primos[i]==0){
			sol /= primos[i];
			sol *= primos[i] - 1;
			while( num % primos[i] == 0)
				num /= primos[i];
		}
	if(num>1){
		sol /= num;
		sol *= num - 1;
	}
	return sol;
}


int main()
{

	sieve();
	for(int i=1; i<21; i++)
		printf("%d -> %d , %d\n",i, funcion_phi(i), phi[i]);
	
	return 0;
}
