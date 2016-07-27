#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int val(char c)
{
	if( c>='A' && c<='Z')
		return 2*(c-'A');
	if( c>='a' && c<='z')
		return 2*(c-'a')+1;
}

bool compara(string s, string t)
{
	for(int i=0; i<s.size(); i++)
		if(val(s[i])!=val(t[i]))
			return val(s[i]) < val(t[i]);
	return true;
}

typedef struct p
{
	string s;
	bool operator < (const struct p &t) const{
		return compara(s,t.s);
	}
}P;

vector<P> sol;

int main()
{
	int nc;
	string s;
	cin >> nc;
	P tmp;
	while(nc--)
	{
		cin >>	s;
		sort(s.begin(),s.end());
		sol.clear();		
		do{
			tmp.s = s;
			sol.push_back(tmp);
		}while(next_permutation(s.begin(),s.end()));
		
		sort(sol.begin(),sol.end());
		
		for(int i=0; i<sol.size(); i++)
			cout << sol[i].s << endl;
	}
	
	return 0;
}
