//10223 - How many nodes ?

#include <stdio.h>

long long int fun(long long int num)
{
	 switch(num)
	 {
	 	case 1: return 1;

		case 2: return 2;

		case 5: return 3;

		case 14: return 4;

		case 42: return 5;

		case 132: return 6;

		case 429: return 7;

		case 1430: return 8;

		case 4862: return 9;

		case 16796: return 10;

		case 58786: return 11;

		case 208012: return 12;

		case 742900: return 13;

		case 2674440: return 14;

		case 9694845: return 15;

		case 35357670: return 16;

		case 129644790: return 17;

		case 477638700: return 18;

		case 1767263190: return 19;

		case 6564120420: return 20;

		default: return -1;
	 }
}

int main()
{
	
	long long int num;
	
	while(scanf("%lld", &num)!=EOF)
		if(fun(num)!=-1)
			printf("%lld\n", fun(num));
	
	return 0;
}

