//583 Primes Factors
#include <stdio.h>
#include <bitset>
#include <vector>
#define MAX 47000
using namespace std;

bitset<MAX> criba;
vector<int> primos;

void sieve(){
	criba.set();
	for(int i=2; i<MAX; i++)
		if(criba[i]){
			primos.push_back(i);
			for(int j=i<<1; j < MAX; j+=i)
				criba.reset(j);
		}
}

void factoriza(int num){
	printf("%d = ", num);
	if(num==1){ 
		printf("1\n"); return;
	}
	int ban= false;
	if(num < 0){ 
		printf("-1");
		num*=-1;
		ban = true;
	}
	for(int i=0; i<primos.size() && primos[i]*primos[i]<=num; i++)
		while(num%primos[i]==0){
			if(ban) printf(" x "); ban=true;
			printf("%d", primos[i]);
			num/=primos[i];
		}
	if(num>1){
		if(ban) printf(" x ");
		printf("%d", num);
	}
	puts("");
}

int main(){
	sieve();
	int num;
	while(scanf("%d", &num), num)	
		factoriza(num);
	return 0;
}
