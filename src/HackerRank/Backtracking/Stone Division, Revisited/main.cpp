#include <stdio.h>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

map<long long int, long long int > mem;


long long int solve(long long int stone_size, long long int * dividers, int ndividers){
    if (stone_size == 1) return 0;

    if (mem[stone_size]) return mem[stone_size];

    long long int movs = 0;

    for (int i = 0; i < ndividers ; i++) {
        if (stone_size % dividers[i] != 0 || dividers[i] == stone_size) continue;
        movs = max(movs, 1 + solve(dividers[i], dividers, ndividers) * (stone_size / dividers[i]));
    }

    mem[stone_size] = movs;

    return movs;
}


int main(int argc, char const *argv[]) {
    int ncases, ndividers;
    long long int stone_size, dividers[1000];

    scanf("%d", &ncases);

    while(ncases--) {
        scanf("%lld %d", &stone_size, &ndividers);

        for (int i = 0; i < ndividers; i++) {
            scanf("%lld", &dividers[i]);
        }

        mem.clear();

        printf("%lld\n", solve(stone_size, dividers, ndividers));
    }

    return 0;
}
