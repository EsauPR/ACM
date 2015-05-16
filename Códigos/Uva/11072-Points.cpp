#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct punto{
	int x, y;
	bool operator < (const struct punto &p) const{
		return y<p.y || y==p.y && x<p.x;
	}
}P;

vector<P> final;
vector<P> puntos;
int N,M;

int area(P p1, P p2, P p3)
{
	return (p1.x-p3.x) * (p2.y-p3.y) - (p1.y-p3.y) * (p2.x-p3.x);
}

void convex()
{
	sort(puntos.begin(), puntos.end());
	int k=0;
	for(int i=0; i<N ; i++)
	{
		while(k>=2 && area(puntos[i], final[k-2], final[k-1] ) <=0 )
			k--;
		final[k++]=puntos[i];
	}
	for(int i=N-2, t = k+1; i>=0; i--  )
	{
		while( k >= t && area(puntos[i], final[k-2], final[k-1] ) <=0 )
			k--;
		final[k++]=puntos[i];	
	}
	final.resize(k-1);
}

bool dentro(P tmp)
{
	for(int i=0; i<final.size(); i++)
		if(area(final[i], final[(i+1)%final.size()], tmp) < 0 )
			return false;
	return true;
}


int main()
{
	P tmp;
	while(1)
	{
		
		scanf("%d", &N);
		if(feof(stdin)) break;
		
		puntos.resize(N);
		final.resize(2*N);
		for(int i=0; i<N; i++)
			scanf("%d %d", &puntos[i].x, &puntos[i].y);
		convex();
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%d %d", &tmp.x, &tmp.y);
			if(dentro(tmp))
				puts("inside");
			else puts("outside");
		}
	}
	return 0;
}
