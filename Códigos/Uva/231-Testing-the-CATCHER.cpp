//231 - Testing the CATCHER
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a,b;

int  TAM;


int LIS()
{
	int maxi=0;
	for(int i=0; i<=TAM; i++)
	{
		b[i]=1;
		for(int j=0; j<i; j++)
			if( a[j]>a[i] ) b[i] = max(b[i],b[j]+1);
		maxi = max(maxi,b[i]);
	}
	return maxi;
}

int main()
{
	int num, k=1;
	while(1){
		a.clear();
		scanf("%d", &num);
		if(num==-1) break;
		while(1){
			a.push_back(num);
			scanf("%d", &num);
			if(num==-1) break;
		}
		TAM = a.size()-1;
		b.resize(a.size());
	//	for(int i=0; i<a.size(); i++)
//			printf("%d ",a[i]);
		if(k!=1) puts("");
		printf("Test #%d:\n", k++);
		printf("  maximum possible interceptions: %d\n",LIS());
		
	}
	
	return 0;
}
