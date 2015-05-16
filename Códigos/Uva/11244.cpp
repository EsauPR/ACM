#include <stdio.h>

char sky[150][150];

int N,M;

int cont, vec[] = {-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};

bool isValid(int i, int j)
{
	if(i>=0 && i<N && j>=0 && j<M)
		return true;
	return false;
}


void fullsky(int i , int j)
{
	if(sky[i][j]!='*')
		return;
	
	sky[i][j]='.';
	
	for(int k=0; k<16; k+=2)
		if(isValid(i+vec[k], j+vec[k+1]))
			fullsky(i+vec[k], j+vec[k+1]);
	
}

bool check(int i, int j)
{
	for(int k=0; k<16; k+=2)
		if( isValid(i+vec[k],j+vec[k+1]) && sky[i+vec[k]][j + vec[k+1]]=='*' )
			return false;
	return true;
		
}

int main()
{
	
	while(scanf("%d %d", &N,&M),N,M)
	{
		cont = 0;
		for(int i=0; i<N; i++)
			scanf("%s", sky[i]);
		
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(sky[i][j]=='*')
				{
					if(check(i,j))
						cont ++;
					fullsky(i,j);
				}
		printf("%d\n", cont);
	} 	
	
	return 0;
}
