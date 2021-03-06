#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct Punto{
	int x, y;
}PUN;

typedef struct Linea{
	PUN a, b;
	int A,B,C;
}LIN;

int gcd(int a, int b, int c)
{
	int div=2;
	int mcd=1;
	while( (div <= abs(a) || a==0) && (div <= abs(b) || b==0 )&& (div <= abs(c) || c==0 ) && abs(a)!=1 && abs(b)!=1 && abs(c)!=1 )
	{
		while(a%div == 0 && b%div == 0 && c%div==0)
		{
			a/=div;
			b/=div;
			c/=div;
			mcd *= div;
		}
		div++; 
	}
	return mcd;
}

void getEcuation(LIN *L)
{
	L->A = L->b.y - L->a.y;
	L->B = L->a.x - L->b.x;
	L->C = (L->a.y - L->b.y) * L->a.x + (L->b.x - L->a.x) * L->a.y;
	int div = gcd(L->A, L->B,L->C);
	L->A /= div; 
	L->B /= div;
	L->C /= div;
}

bool SegSegInt(PUN a, PUN b, PUN c, PUN d, int ca){
	double s,t,num,denom;
	denom=a.x * double(d.y - c.y) + b.x * double(c.y - d.y) + d.x * double(b.y - a.y) + c.x * double(a.y - b.y);
	//paralelos
	if(denom==0.0) return false;
	num=a.x * double(d.y - c.y) + c.x * double(a.y - d.y) + d.x * double(c.y - a.y);
	s=num/denom;
	num= - (a.x * double(c.y - b.y) + b.x * double(a.y - c.y) + c.x * double(b.y - a.y));
	t=num/denom;
	//*p.x=a.x + s * (b.x - a.x);
	//*p.y=a.y + s * (b.y - a.y);
	if(ca == 1)	return (0.0 <= s && s <= 1.0 && 0.0 <= t && t <= 1.0); // seg-seg
	if(ca == 2) return (0.0<=s&&s<=1.0); // seg-linea
	if(ca == 3) return true; // linea- linea
}

int main()
{

	LIN a,b;
	char pal1[10], pal2[10];
	int ca;
	while(true)	
	{
		scanf("%d %d %d %d %s", &a.a.x, &a.a.y, &a.b.x, &a.b.y, pal1);
		scanf("%d %d %d %d %s", &b.a.x, &b.a.y, &b.b.x, &b.b.y, pal2);
		if(strcmp(pal1,"END")==0)
			break;
		if( strcmp(pal1,pal2)==0 )
		{
			if(strcmp(pal1,"L")==0)
				ca = 3;
			else ca = 1;
		}
		else ca = 2;
		
		
		if(SegSegInt(a.a, a.b, b.a,b.b, ca))
			puts("si");
		else if( (a.A == b.A && a.B == b.B && a.C == b.C) || (a.A == -b.A && a.B == -b.B && a.C == -b.C) )
				puts("0.00000");
		else puts("NONE");
		
	}
	
	return 0;
}
