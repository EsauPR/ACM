//627 Thne Net
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

map<int,vector<int> > g;
map<int,int > visit;

bool bfs(int s, int t)
{
	visit.clear();
	queue<int> cola;
	cola.push(s);
	visit[s] = s;
	int act;
	while(!cola.empty())
	{
		act = cola.front(); cola.pop();
		for( int i=0; i < g[act].size(); i++ )
			if( visit[ g[act][i] ] == 0 )
			{
				visit[g[act][i]] = act;
				if( g[act][i] == t )
					return true;
				cola.push(g[act][i]);
			}
	}
	return false;
}

void print(int s, int t)
{
	if(s == t)
	{
		printf("%d", s);
		return;
	}
	print(s, visit[t]);
	printf(" %d", t);
}

int main()
{
	int nn, num,nod,a,b;
	char s[10000], *ptr;
	
	while( scanf( "%d\n" , &nn ) != EOF )
	{
		g.clear();
		for(int i=0; i<nn; i++)	
		{
			gets(s);
			ptr = strtok( s , "-," );
			if(ptr)
				sscanf(ptr,"%d",&num);
			for( ; ptr!=NULL; )
			{
				ptr = strtok( NULL , "-," );
				if(ptr)
				{
					sscanf(ptr,"%d",&nod);
					g[num].push_back(nod);
				}
			}
		}
		puts("-----");
		scanf("%d", &nn);
		for(int i=0; i<nn; i++)
		{
			scanf("%d %d\n", &a,&b);
			if(bfs(a,b))
			{
				print(a,b);
				puts("");
			}
			else puts("connection impossible");
		}		
	}
	
	return 0;
}
