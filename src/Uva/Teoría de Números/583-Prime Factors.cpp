/*
    Problem: Prime factors
    Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524
*/
#include <stdio.h>
#include <bitset>
#include <vector>

using namespace std;

#define MAX 46341

bitset<MAX> sieve;
vector<int> primes;

void c_sieve() {
    sieve.set();
    for (int i = 2; i < MAX; i++) {
        if (sieve.test(i)) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j+=i) {
                sieve.reset(j);
            }
        }
    }
}

void prime_factor(int number, bool is_negative) {
    bool print_X = is_negative;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= number; i++) {
        while (number % primes[i] == 0) {
            number /= primes[i];
            if (print_X) {
                printf(" x %d", primes[i]);
            }
            else {
                printf(" %d", primes[i] );
            }
            print_X = true;
        }
    }

    if (number != 1) {
        if (print_X) {
            printf(" x %d", number);
        } else {
            printf(" %d", number);
        }
    }
}

int main(int argc, char const *argv[]){
    int number;
    c_sieve();

    while(scanf("%d", &number), number) {
        if (number < 0) {
            printf("%d = -1", number);
            prime_factor(-number, true);
        } else {
            printf("%d =", number);
            prime_factor(number, false);
        }
        puts("");
    }

    return 0;
}
