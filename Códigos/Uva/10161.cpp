#include <stdio.h>

int x, y, num;

int fun(int n){
	return n*n-n+1;
}

int pos(int n){
	int i;
	for( i=1; fun(i)<n; i++); return i;
}

void check(int pos)
{
	y = x = pos;
	
	if(num == fun(pos)) return;
	
	if(num + pos-1 < fun(pos)) pos--;
	
	//printf("pos %d\n",fun(pos));
	
	y = x = pos;

	if(pos & 1)
	{
		if(num-fun(pos) > 0)
			x -= num-fun(pos);
		else
			y -= fun(pos)-num;
	}
	else
	{
		if(num-fun(pos) > 0)
			y -= num-fun(pos);
		else
			x -= fun(pos)-num;
	}
}

int main()
{
	
	while(scanf("%d", &num), num)
	{
		check(pos(num));
		printf("%d %d\n",x,y);
	}
	
	return 0;
}
