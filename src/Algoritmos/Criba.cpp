#include <stdio.h>
#include <vector>
#include <bitset>
#define MAX 47000
using namespace std;

vector<int> primos;
bitset<MAX> criba;

void llenacriba(){
	criba.set();
	criba.reset(0); criba.reset(1);
	for( int i = 2; i < MAX; i++ )
		if( criba[ i ] ) {
			primos.push_back( i );
			for( int j = i<<1; j < MAX; j+=i )
				criba.reset(j);
		}
}

int main(){

	llenacriba();

	return 0;
}
