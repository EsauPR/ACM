// 1530 uva 1067 coj Guessing Game

#include <stdio.h>
#include <string.h>


int main()
{
	
	char pal[20];
	int min=0; int max=11, num;
	
	while(1)
	{
		scanf("%d\n", &num);
		gets(pal);

		if(feof(stdin)) break;
		
		if(strcmp(pal,"too high")==0)
		{
			if(num < max && num > min)
				max=num;
			
		}		
		
		if(strcmp(pal,"too low")==0)
		{
			if(num > min && num < max)
				min=num;
			
		}		
		if(strcmp(pal,"right on")==0)
		{
			if(num > min && num < max)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			
			max=11;
			min=0;
		}		
		
	}	
	return 0;
}
