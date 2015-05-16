//10245 The Closest Pair Problem

#include <stdio.h>
#include <algorithm>
#include <math.h>
#define INF 1<<30
using namespace std;

typedef struct punto{
	double x, y;

	bool operator <	(const struct punto &p) const
	{
		return x<p.x || ( x==p.x && y<p.y );
	}
	bool operator >	(const struct punto &p) const
	{
		return x>p.x || ( x==p.x && y>p.y );
	}
}Punto;

Punto a[10001];
int nc;

void print()
{
	for(int i=0; i<nc; i++)
			printf("%lf-%lf ", a[i].x,a[i].y);
		puts("");
}
void mysort(int ini, int fin)
{
        if(ini>=fin)
            return;
        int i=ini;
        int j=fin;
        
        Punto mit=a[(ini+fin)/2];

        while(i<=j)
        {
            while(a[i]<mit) i++;
            while(a[j]>mit) j--;
            if(i<=j){
                Punto t=a[i];
                a[i]=a[j];
                a[j]=t;
                i++;
                j--;
            }
        }
       // print();
        if(i<fin) mysort(i,fin);
        if(j>ini) mysort(ini,j);
}

double dis(Punto p1, Punto p2)
{
	return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

double solve(int s, int t)
{
	if(s==t)	return INF;
	if(t-s == 1)	return dis(a[s], a[t]);
	
	int m = (t+s)/2;
	double tmp;
	
	tmp = min( solve(s,m), solve(m+1,t)  );

	int ini,fin;
	if( (t-s) < 16 ) {
		ini = s;	fin = t;
	}
	else{
		ini = m-7;	fin = m+8;
	}
	//printf("ini==%d FIN===%d %d %d\n",ini,fin,s,t);
	for(int i=ini; i<fin; i++)
		for(int j=i+1; j<=fin; j++)
			tmp = min(tmp, dis(a[i],a[j]));
	return tmp;
	
}

int main()
{
	while(scanf("%d", &nc),nc)
	{
		for(int i=0; i<nc; i++)
			scanf("%lf %lf", &a[i].x, &a[i].y);
/*
		for(int i=0; i<nc; i++)
			printf("%lf-%lf ", a[i].x,a[i].y);
		puts("");		*/
//		sort(a,a+nc);
		mysort(0,nc-1);
		double sol = solve(0,nc-1);
		if(sol<10000.00)
			printf("%.4lf\n", sol );
		else puts("INFINITY");
		
	}
	return 0;
}
