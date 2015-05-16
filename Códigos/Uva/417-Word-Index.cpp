//417 word index
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<string,int> mapa;

char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main()
{
	char pal[1000];
	int cont=1, total;
	
	string s1="", s2="",s3="",s4="",s5="";
	for(int i=0; i<26; i++)
		{
			s2 = alpha[i];
			mapa[s2] = cont++;
		}
		
		for(int i=0; i<26; i++)
		{
			s1 = alpha[i];
		
			for(int j=i+1; j<26; j++)
			{
				s2 = s1 + alpha[j];
				mapa[s2] = cont++;
			}
		}

		for(int k=0; k<26; k++)
		{	
			s3=alpha[k];
			for(int i=k+1; i<26; i++)
			{
				s1 = s3 + alpha[i];
		
				for(int j=i+1; j<26; j++)
				{
					s2 = s1 + alpha[j];
					mapa[s2] = cont++;
				}
			}
		}
		for(int m=0; m<26; m++)
		{
			s4 = alpha[m];
			for(int k=m+1; k<26; k++)
			{	
				s3= s4 + alpha[k];
				for(int i=k+1; i<26; i++)
				{
					s1 = s3 + alpha[i];
		
					for(int j=i+1; j<26; j++)
					{
						s2 = s1 + alpha[j];
						mapa[s2] = cont++;
					}
				}
			}
		}
		
		for(int r=0; r<26; r++)
		{
			s5 = alpha[r];
			for(int m=r+1; m<26; m++)
			{
				s4 = s5 + alpha[m];
				for(int k=m+1; k<26; k++)
				{	
					s3= s4 + alpha[k];
					for(int i=k+1; i<26; i++)
					{
						s1 = s3 + alpha[i];
		
						for(int j=i+1; j<26; j++)
						{
							s2 = s1 + alpha[j];
							mapa[s2] = cont++;
						}
					}
				}
			}
		}
	
	string res;
	while(1)
	{
		cin >> res;
		if(feof(stdin)) break;
		
		
		if(mapa.count(res)!=0)
			printf("%d\n",mapa[res]);
		else puts("0");
		
		
	}
	
	return 0;
}
