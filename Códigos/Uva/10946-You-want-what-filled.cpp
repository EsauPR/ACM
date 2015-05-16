//10946 - You want what filled?
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;


typedef struct nodo{
	char l; int num;

	bool operator < (const struct nodo &p) const{
		if(num > p.num)	return true;
		if( num == p.num) 
			if(p.l > l) return true;
		return false;
	}
}Nodo;

vector<Nodo> vec;

int N,M;
char mat[100][100];
int pos[] = {1,0,-1,0,0,1,0,-1};

bool isVal(int i, int j){
	return (i>=0 && i<N && j>=0 && j<M)?true:false;
}

void bfs(int x, int y){
	Nodo p;
	queue<pair<int,int> > cola;
	p.l = mat[x][y];
	p.num = 1;
	mat[x][y] = '.';
	cola.push(make_pair(x,y));
	
	while(!cola.empty())
	{
		pair<int,int> tmp = cola.front();
		cola.pop();
		
		for(int i=0; i<8; i+=2)
			if( isVal(tmp.first+pos[i], tmp.second+pos[i+1]) && mat[tmp.first + pos[i]][tmp.second+pos[i+1]] == p.l)
			{
				p.num++;
				mat[tmp.first + pos[i]][tmp.second+pos[i+1]] = '.';
				cola.push(make_pair(tmp.first+pos[i], tmp.second+pos[i+1]));
			}
	}
	vec.push_back(p);
}

int main()
{	
	int t=1;
	while(scanf("%d%d", &N, &M),N,M)
	{
		vec.clear();
		for(int i=0; i<N; i++)
			scanf("%s", mat[i]);
		
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(mat[i][j]!='.')
					bfs(i,j);
		sort(vec.begin(),vec.end());
		printf("Problem %d:\n", t++);
		for(int i=0; i<vec.size(); i++)
			printf("%c %d\n", vec[i].l,vec[i].num);
	}
	
	return 0;
}
