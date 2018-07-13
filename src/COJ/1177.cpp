//1177 - Group Reverse

#include <stdio.h>
#include <string.h>

char vec[200];
void voltea(int i, int j){
	char tmp;
	while(i<j){
		tmp=vec[i];
		vec[i++]=vec[j];
		vec[j--]=tmp;
	}
}

int main(){


	int n,k;

	while(scanf("%d%s",&n,vec),n){
		k=strlen(vec)/n;
		for(int i=0; i<strlen(vec); i+=k){
			voltea(i, i+k-1);
		}
		puts(vec);
	}
	
	
	
	
	return 0;
}
