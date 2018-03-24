#include <iostream>
using namespace std;

#define MAX 60

long long int fib[MAX];

void calcula_fibonacci() {
    fib[0] = 0LL;
    fib[1] = 1LL;

    for (int i = 2; i < MAX; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main(int argc, char const *argv[])
{
    int case_num = 0, n;
    cin >> case_num;

    calcula_fibonacci();
    for( int i = 0; i < case_num; i++) {
        cin >> n;
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << fib[n+2] << endl << endl;
    }

    return 0;
}
