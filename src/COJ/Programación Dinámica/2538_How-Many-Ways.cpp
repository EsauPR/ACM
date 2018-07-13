#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001
#define MOD  1000000000

int numbers[MAX], n;
int mem[MAX][3];

int solve(int ind, int sum) {
    if (ind == n) {
        return 0;
    }

    if (mem[ind][sum] != -1) {
        return mem[ind][sum];
    }
    
    if ((sum + numbers[ind]) % 3 == 0) {
        return mem[ind][sum] = (1 + solve(ind + 1, (sum + numbers[ind]) % 3) + solve(ind + 1, sum)) % MOD;
    }

    return mem[ind][sum] = (solve(ind + 1, (sum + numbers[ind]) % 3) + solve(ind + 1, sum)) % MOD;
}

int main(int argc, char const *argv[]) {
    memset(mem, -1, sizeof(mem));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("%d\n", solve(0, 0));
    
    return 0;
}