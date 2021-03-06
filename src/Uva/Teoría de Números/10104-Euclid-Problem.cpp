//10104 - Euclid Problem
#include <stdio.h>


int gcd(int a, int b, int *x, int *y) {
	if (b==0){
		*x=1;
		*y=0;
		return a;
	}
	int xp,yp,g;
	g=gcd(b,a%b,&xp,&yp);
	*x=yp;
	*y=xp-(a/b)*yp;
	return g;
}

int main() {
	int a, b,x,y;
	while(scanf("%d %d", &a,&b) != EOF)
	{
		int res = gcd(a,b,&x,&y);
		printf("%d %d %d\n", x , y, res);
	}
	
	return 0;
}
