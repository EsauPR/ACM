//941 - Permutations  
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
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

void ordena(string &s)
{
	vector<char> tmp;
	for(int i=0; i<s.size(); i++)
		tmp.push_back(s[i]);
	sort(tmp.begin(), tmp.end());
	for(int i=0; i<s.size(); i++)
		s[i]=tmp[i];
}


int main()
{
	string s;
	LL x;
	fact[0]=1;
	for(int i=1; i<21; i++)
	fact[i] = fact[i-1]*i;
	int nc;
	scanf("%d", &nc);
	while(nc--)
	{
		cin >>s;
		scanf("%lld", &x);
		ordena(s);
		permu(s,x % fact[s.size()],s.size()-1);
		puts("");
	}
	return 0;
}
