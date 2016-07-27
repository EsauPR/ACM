#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int LL;

LL fact[25];

void permu(string s, LL x, int l)
{
	if(l<0) return;
	LL p = x/fact[l];
	printf("%c", s[p]);
	s = s.substr(0,p) + s.substr(p+1,s.size()-p);
	permu(s,x%fact[l],l-1);
}

int main()
{

	fact[0]=1;
	for(int i=1; i<21; i++)
		fact[i] = fact[i-1]*i;
	string s = "abcd";
	
	LL x;
	
	scanf("%lld", &x);
	
	permu(s,x % fact[s.size()],s.size()-1);
	puts("");

	return 0;
}
