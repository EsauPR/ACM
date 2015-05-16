//460 - Overlapping Rectangles

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct punto{
	int x, y;	
}p;

typedef struct rec{
	p a,b;
}r;

bool isvalid(r rec){
	return ( rec.a.x < rec.b.x && rec.a.y < rec.b.y);
}

int main()
{
	int nc;
	scanf("%d", &nc);
	r r1,r2,r3;
	while(nc--)
	{
		
		scanf("%d %d %d %d %d %d %d %d", &r1.a.x, &r1.a.y, &r1.b.x, &r1.b.y, &r2.a.x, &r2.a.y, &r2.b.x, &r2.b.y);
		r3.a.x = max( r1.a.x, r2.a.x );
		r3.a.y = max( r1.a.y, r2.a.y );
		r3.b.x = min( r1.b.x, r2.b.x );
		r3.b.y = min( r1.b.y, r2.b.y );
		
		if(isvalid(r3))  printf("%d %d %d %d\n",r3.a.x, r3.a.y, r3.b.x, r3.b.y);
		else puts("No Overlap");
		
		if(nc) puts("");
	}
	
	return 0;	
}
