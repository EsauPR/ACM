//10340 - All in All
#include <stdio.h>

char a[1000009], b[1000009];

int main()
{
	
	int i=0,j=0;
	
	while(scanf("%s%s",a,b)!=EOF)
	{
		//printf("%s %s\n",a,b);

		for(i=0, j=0; b[i] != '\0' && a[j] != '\0' ; i++)
			if(a[j] == b[i])
				j++;
		if(a[j]=='\0') puts("Yes");
			else puts("No");
	}
	
	return 0;
}