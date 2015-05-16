//587 - There's treasure everywhere!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double dist(double x, double y)
{
	return sqrt( x*x + y*y );
}

int main()
{
	char pal[300], num[30], pos[10]; 
	int cant, time=1;
	while( scanf("%s", pal) != EOF)
	{
		if(strcmp(pal, "END")==0)
			break;
		double x = 0.0, y = 0.0;
		
		for(int i=0, k=0, m=0; pal[i] != '\0'; i++)
		{
			if(pal[i]>='0' && pal[i]<='9')
				num[k++] = pal[i];
			else if( pal[i] == ',' || pal[i] == '.' )
			{
				num[k] = pos[m] = '\0';
				k=0; m=0;
				cant = atoi(num);
				
				if(strcmp(pos,"N")==0)
					y += cant;
				if(strcmp(pos,"S")==0)
					y -= cant;
				if(strcmp(pos,"E")==0)
					x += cant;
				if(strcmp(pos,"W")==0)
					x -= cant;
				if(strcmp(pos,"NE")==0)
				{
					y += (double)cant*0.707106781;
					x += (double)cant*0.707106781;
				}
				if(strcmp(pos,"NW")==0)
				{
					y += (double)cant*0.707106781;
					x -= (double)cant*0.707106781;
				}
				if(strcmp(pos,"SE")==0)
				{
					y -= (double)cant*0.707106781;
					x += (double)cant*0.707106781;
				}
				if(strcmp(pos,"SW")==0)
				{
					y -= (double)cant*0.707106781;
					x -= (double)cant*0.707106781;
				}
			}
			else 
				pos[m++] = pal[i];
		}		
		printf("Map #%d\n",time++);
		printf("The treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n",x,y,dist(x,y));
	}
	
	return 0;
}
