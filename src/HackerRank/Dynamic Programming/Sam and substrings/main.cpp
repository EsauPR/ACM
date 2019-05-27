/*
    https://www.hackerrank.com/challenges/sam-and-substrings/problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main(){
    char number[200001];

    scanf("%s", number);

    long long int sl[2] = {0, 0}, st[2] = {0, 0}, i;
    long long int pow_sum = 1;
    int len = strlen(number);

    for (i = 0; i < len; i++) {
        sl[(i + 1) % 2] = (((number[strlen(number) - i - 1] - '0') * pow_sum) % MOD + sl[i % 2]) %  MOD;
        st[(i + 1) % 2] = (sl[(i + 1) % 2] + st[i % 2]) % MOD;
        pow_sum = (((pow_sum % MOD) * 10) % MOD) + 1 % MOD;
    }

    printf("%lld\n", st[i % 2]);

	return 0;
}
