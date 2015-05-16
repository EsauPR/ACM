//1252 - The Seven Percent Solution

#include <stdio.h>
#include <iostream>
using namespace std;


void print(char c){
	switch(c){
		case ' ':	cout << "%20";
					break;
		case '!':	cout << "%21";
					break;
		case '$':	cout << "%24";
					break;
		case '%':	cout << "%25";
					break;
		case '(':	cout << "%28";
					break;
		case ')':	cout << "%29";
					break;
		case '*':	cout << "%2a";
					break;
		default : printf("%c",c);
	}
}

int main(){
	char vec[100];
	while(1){
		gets(vec);
		if(vec[0]=='#')
			break;
		for(int i=0; vec[i]!='\0'; i++)
			print(vec[i]);
		printf("\n");
	}
	return 0;
}
