//1244 - Flowers Flourish from France

#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;

char fun(char c){
	if(c>='A' && c<='Z')
		return c-'A'+'a';
	return c;
}

int main(){
	
	char vec[2000],c,k;
	int b=0;
	string res;
	while(1){
		b=0;
		gets(vec);
		k=vec[0];
		if(k=='*')
			break;
		k=fun(k);
		istringstream flujoin( vec );

		while(flujoin >> res){
			c=res[0];
			c=fun(c);
			if(c!=k)
				b=1;
		}
		(b==0)? printf("Y\n") : printf("N\n");
	}
	
	return 0;
}
