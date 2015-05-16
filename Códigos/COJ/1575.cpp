#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector<vector<int > > mat;
int N, Nb;
int pos[11];
int fat[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};

bool quitar(int n)
{
	for(int i=1; i<=N; i++)
		if(pos[i]!=-1)
		{
			for(int j=0; j<mat[i].size(); j++)
				if(mat[i][j] == n)
				{
		//			printf("MAt[%d][%d] = %d, N = %d\n",i,j,mat[i][j],n);
					return false;
				}
		}
	return true;
}

int solve(int t)
{	
	if(t==N)
		return 1;
	int tmp=0;
	for(int i=1; i<=N; i++)
	{
		if(pos[i]!=-1)
		{
			if(quitar(i))
			{
				//printf("Quito %d \n", i);
				pos[i]=-1;
				tmp +=  solve(t+1);
				pos[i]=1;
				
			}
		}
	}
	return tmp;
}

int main()
{
	int a, b;
	
	while(scanf("%d %d", &N, &Nb)!=EOF)
	{
		mat.clear();
		mat.resize(11);
		memset(pos,-1,sizeof(int)*11);
		for(int i=0; i<Nb; i++)
		{
			scanf("%d %d", &a, &b);
			mat[a].push_back(b);
			pos[a]=pos[b]=1;
		}
		
		if(Nb==0)
			printf("%d\n", fat[N]);
		else printf("%d\n", solve(0));
	}
	return 0;
}
