//11364-Parking.cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
vector<int> vec;

int main()
{
	int nc,n,num;
	
	scanf("%d", &nc);
	while(nc--){
		vec.clear();
		scanf("%d",&n);
		while(n--){
			scanf("%d", &num);
			vec.pb(num);
		}
		sort( vec.begin(), vec.end() );
		printf("%d\n", (vec[vec.size()-1] - vec[0])*2);
	}
	
	return 0;
}
