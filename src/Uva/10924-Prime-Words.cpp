//10924 Prime Words
#include<stdio.h>
#include <bitset>
#define MAX 1100
using namespace std;

bitset<MAX> criba;
char pal[100];

void llenacriba()
{
	criba.set();
	criba.reset(0);
	for(int i=2; i<MAX; i++)
		if(criba[i])
			for(int j=i<<1; j<MAX; j+=i)
				criba.reset(j);
}

int val(char c)
{
	if(c>='A' && c<='Z') return c-'A'+27;
	if(c>='a' && c<='z') return c-'a'+1;
	return 0;
}

int main()
{
	
	llenacriba();
	int sol;
	while(scanf("%s", pal)!=EOF)
	{
		sol=0;
		for(int i=0; pal[i]!='\0'; i++)
			sol +=  val(pal[i]);
		//printf("%d ",sol);
		if(criba[sol])
			puts("It is a prime word.");
		else puts("It is not a prime word.");
	}
	
	return 0;
}
