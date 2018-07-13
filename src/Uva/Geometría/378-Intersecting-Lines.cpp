//378 - Intersecting Lines
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Punto{
	int x, y;
}PUN;

typedef struct PuntoDouble{
	double x, y;
}PUND;

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

bool Intersection(LIN *l1, LIN *l2, PUND *p)
{
	double s,t,num,denom;
	getEcuation(l1);
	getEcuation(l2);
	denom = l1->A * l2->B - l2->A * l1->B;
	if(denom == 0.0) return false; 	//paralelos
	num = l1->B * l2->C - l1->C * l2->B;
	s=num/denom;
	num = l2->A * l1->C - l2->C * l1->A;
	t=num/denom;
	p->x = s;
	p->y = t;
	return true;
}

int main()
{
	int nc;
	PUND p;
	LIN a,b;
	scanf("%d", &nc);
	puts("INTERSECTING LINES OUTPUT");
	while(nc--)	
	{
		scanf("%d %d %d %d %d %d %d %d", &a.a.x, &a.a.y, &a.b.x, &a.b.y, &b.a.x, &b.a.y, &b.b.x, &b.b.y);
		
		if(Intersection(&a, &b, &p))
			printf("POINT %.2lf %.2lf\n", p.x, p.y);
		else if( (a.A == b.A && a.B == b.B && a.C == b.C) || (a.A == -b.A && a.B == -b.B && a.C == -b.C) )
				puts("LINE");
		else puts("NONE");
		
	}
	puts("END OF OUTPUT");

	return 0;
}
