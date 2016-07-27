//10653-Bombs! NO they are Mines!!
#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

int g[1005][1005], N,M;
int pos[] = {0,1,0,-1,1,0,-1,0};

bool isvalid(int x, int y){
	return ( x<N && x>=0 && y<M && y>=0 );
}

int bfs(int sx, int sy, int tx, int ty)
{
	int ax,ay,bx,by;
	queue<int> cola;
	g[sx][sy]=1;
	cola.push(sx);
	cola.push(sy);
	
	while(!cola.empty())
	{
		ax = cola.front(); cola.pop();
		ay = cola.front(); cola.pop();
		for(int i=0 ; i<8; i+=2)
		{
			bx = ax + pos[i];
			by = ay + pos[i+1];
			if(isvalid(bx,by) && g[bx][by]==0)
			{
				g[bx][by] = g[ax][ay] + 1;
				cola.push(bx);
				cola.push(by);
			}
			if(bx==tx && by==ty) return g[tx][ty]-1;
		}
	}
}

int main()
{
	int nb, row, bom, nbom, sx,sy, tx,ty;
	while(scanf("%d %d", &N, &M),N,M)
	{
		memset(g,0,sizeof(g));
		scanf("%d", &nb);
		while(nb--)
		{
			scanf("%d %d", &row, &nbom);
			while(nbom--)
			{
				scanf("%d", &bom);
				g[row][bom] = -1;
			}
		}
		scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
		printf("%d\n",bfs(sx,sy,tx,ty) );
	}
	
	return 0;
}
