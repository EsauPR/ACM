#include <stdio.h>
#include <stdlib.h>
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

int legendre_formula(int prime, int number) {
    int count = 0;
    for (int i = prime; i <= number; i*=prime) {
        count += number/i;
    }
    return count;
}

bool solve(int n, int m) {
    if (n >= m) return true;

    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= m; i++) {
        int prime_count = 0;
        while (m % primes[i] == 0) {
            m /= primes[i];
            prime_count ++;
        }
        if (legendre_formula(primes[i], n) < prime_count) {
            return false;
        }
    }
    if (m > 1 && m > n) {
        return false;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    int n, m;
    c_sieve();

    while( scanf("%d %d", &n, &m) != EOF ) {
        if (solve(n, m)) {
            printf("%d divides %d!\n", m, n);
        }
        else {
            printf("%d does not divide %d!\n", m, n);
        }
    }
    return 0;
}
