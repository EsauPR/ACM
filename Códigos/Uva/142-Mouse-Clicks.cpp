#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Punto{
	int x, y;
}PUN;

typedef struct Rectangulo{
	PUN a, b;
}REC;

typedef struct icon{
	PUN p;
	bool visible;
	int dis;
}ICON;

REC VREC[60];
ICON VICON[60];
int nr, ni;

void reconf(REC * R){
	PUN tmp1 , tmp2;
	tmp1.x = min(R->a.x, R->b.x);
	tmp2.x = max(R->a.x, R->b.x);
	tmp1.y = min(R->a.y, R->b.y);
	tmp2.y = max(R->a.y, R->b.y);
	R->a = tmp1;     R->b = tmp2;
}

int dist(PUN a, PUN b){
	return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

bool inRec(PUN p, REC r){
	if( p.x <= r.b.x && p.x >= r.a.x && p.y >= r.a.y && p.y <= r.b.y)
		return true;
	return false;
}

bool dentro(PUN p)
{
	for(int i=nr-1; i>=0; i--)
	{
		if( inRec( p, VREC[i] ) )
		{
			printf("%c\n", 'A' + i);
			return true;
		}
	}
	return false;
}

void ocultar()
{
	for(int i=0; i < ni; i++)
		for(int j=0; j < nr; j++)
			if( inRec( VICON[i].p , VREC[j] ) )
			{
				VICON[i].visible = false;
			}
}

void checkIcons( PUN p )
{
	int min = 1<<30;
	for(int i=0; i<ni; i++)
	{
		if(VICON[i].visible)
		{
			VICON[i].dis = dist(VICON[i].p , p);
			if(VICON[i].dis < min)
				min = VICON[i].dis;
		}
	}
	
	for(int i=0; i<ni; i++)
		if(VICON[i].visible && VICON[i].dis == min)
			printf("%3d", i+1);
	puts("");
}

int main()
{	
	char c;
	REC rt;
	PUN p;
	
	while(scanf("%c", &c), c!='M')
	{
		if( c == 'R')
		{
			scanf("%d %d %d %d\n",&(rt.a.x) , &(rt.a.y), &(rt.b.x), &(rt.b.y) );
			reconf(&rt);
			VREC[nr++]=rt;
		}
		else if( c == 'I' )
		{
			scanf("%d %d\n", &(VICON[ni].p.x) , &(VICON[ni].p.y));
			VICON[ni++].visible = true;
		}
	}
	
	ocultar();
	
	while(c != '#')
	{
		scanf("%d %d\n", &(p.x), &(p.y));
		if( !dentro(p) )
			checkIcons(p);
		scanf("%c", &c);
	}
	
	return 0;
}
