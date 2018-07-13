#include <stdio.h>
#include <string.h>

char mat[40][80];
int k, M;
void rei()
{
	for(int i=0; i<32; i++)
		for(int j=0; j<82; j++ )
			mat[i][j]=' ';
}

int main()
{
	
	while(1)
	{
		k=M=0;
		while(1)
		{
			scanf("%s", mat[k]);
			if(mat[k][0]=='_') break;
			if(strlen(mat[k])>M)
				M = strlen(mat[k]);
			mat[k][M]=' ';
		}
		
		for(int i=0; i<k; i++)
			for(int j=0; j<M; j++)
				if(mat[i][j]!=' ' && ischar(mat[i][j]) )
		
	}
	
	return 0;
}
