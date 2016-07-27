#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Punto{
	int x, y;
}PUN;

typedef struct Rectangulo{
	PUN a, b;
}REC;

typedef struct Circulo{
	PUN C;
	double Radio;
}CIR;

typedef struct Linea{
	PUN a, b;
}LIN;

void reconf(REC * R){
	PUN tmp1 , tmp2;
	tmp1.x = min(R->a.x, R->b.x);
	tmp2.x = max(R->a.x, R->b.x);
	tmp1.y = min(R->a.y, R->b.y);
	tmp2.y = max(R->a.y, R->b.y);
	R->a = tmp1;     R->b = tmp2;
}

double dist(PUN a, PUN b){
	return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

bool inRec(PUN p, REC r){ 
	if( p.x <= r.b.x && p.x >= r.a.x && p.y >= r.a.y && p.y <= r.b.y)
		return true;
	return false;
}

int areaTri(PUN a, PUN b, PUN c){
	return (c.x-a.x) * (b.y-a.y) - (c.y-a.y) * (b.x-a.x);
}

bool inTri(PUN p1, PUN p2, PUN p3, PUN p){ // Punto dentro triangulo
	int A1 = areaTri(p1,p2,p);
	int A2 = areaTri(p2,p3,p);
	int A3 = areaTri(p3,p1,p);
	if( (A1>=0 && A2>=0 && A3>=0) || (A1<=0 && A2<=0 && A3<=0) )
		return true;
	return false;
}

double fabs(double a){
	return (a<0)? -a:a;
}

double getArea(vector<PUN> v, int n){ // Area de pilogono
	double suma = 0;	int j; 
	for(int i=0; i<n; i++){ 
		j=(i+1)%n; 
		suma+= v[j].x*v[i].y - v[j].y*v[i].x; 
	} 
	return fabs(suma)/2;
}

bool SegSegInt(PUN a, PUN b, PUN c, PUN d, PUN *p){
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
	return (0.0 <= s && s <= 1.0 && 0.0 <= t && t <= 1.0); // seg-seg
	return (0.0<=s&&s<=1.0); // seg-linea
	// return true; // linea- linea
}

int main()
{	
	return 0;
}
