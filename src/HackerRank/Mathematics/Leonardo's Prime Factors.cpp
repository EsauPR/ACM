/*
    Problem: Leonardo's Prime Factors
    url: https://www.hackerrank.com/challenges/leonardo-and-prime/problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <vector>

using namespace std;

#define GOAL 1000000000000000001LL
#define MAX 200
#define lli long long int

bitset<MAX> criba;
vector<lli> primes;

void set_criba(){
    criba.set();
    criba.reset(0); criba.reset(1);
    for( lli i = 2; i < MAX; i++ ) {
        if( criba.test(i)) {
            primes.push_back( i );
            for( lli j = i*i; j < MAX; j+=i ) {
                criba.reset(j);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    lli cases, num;
    set_criba();

    scanf("%lld", &cases);
    while(cases--) {
        scanf("%lld", &num);

        lli acum = 1;
        int count = 0;
        int num2 = (double)num;
        while (num >= 1) {
            num /= primes[count];
            acum *= primes[count++];
        }
        printf("%d\n", count - 1);
    }

}
