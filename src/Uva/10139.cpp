//10139 - Factovisors
#include <stdio.h>
#include <vector>
#include <bitset>
#include <map>
#define MAXPRIME 47000
using namespace std;

bitset < MAXPRIME > criba;
vector < int > primos;
vector < pair<int,int> > factoresc;

void fullcriba(){
	int i, j;
	criba.set();
	criba.reset(0);
	criba.reset(1);
	for (i=2;i<MAXPRIME;i++){
		if (criba.test(i)){
			primos.push_back(i);
			for (j=2*i;j<MAXPRIME;j+=i)
				criba.reset(j);
		}
	}
}

void factoriza(int n){
   int i = 0;
   map <int, int > factc;
   
   while(i<primos.size() && primos[i]* primos[i] <= n)
      if(n % primos[i] == 0)
         factc[ primos[i] ]++,
         n /= primos[ i ];
      else
         i++;
   if(n > 1)
      factc [ n ]++;
  map <int, int> :: iterator it;
  factoresc.clear();
  for(it=factc.begin();it!=factc.end();it++)
      factoresc.push_back(*it);
}

bool solve(int n, int div)
{	
	factoriza(div);
	
	int tmp, cont;
	for(int i=0; i<factoresc.size(); i++)
	{
		tmp=n;
		cont=0;
		while(tmp)
		{
			cont+=tmp/factoresc[i].first;
			tmp /= factoresc[i].first;
		}
		if(factoresc[i].second>cont) return false;
	}
	return true;
	
}

int main()
{
	int num,div;
	fullcriba();
	while(scanf("%d %d", &num,&div)!=EOF)
	{
		if(div<=num) printf("%d divides %d!\n", div, num);
		else
		{
			if(solve(num,div)) printf("%d divides %d!\n", div, num);
			else printf("%d does not divide %d!\n", div, num);
		}
	}
		
	
	return 0;
}
