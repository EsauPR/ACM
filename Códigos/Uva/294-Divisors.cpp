#include <stdio.h>
#include <bitset>
#include <vector>
#include <map>
#define MAX 47000
using namespace std;

bitset<MAX> criba;
vector<int> primos;
map<int, int> mapa;
map<int, int> ::iterator it;

void llenacriba()
{
        criba.set();
        criba.reset(0); criba.reset(1);
        for(int i=2; i<MAX; i++)
                if(criba[i])
                {
                        primos.push_back(i);
                        for(int j=i<<1; j<MAX; j+=i)
                                criba.reset(j);
                }
}

long long int solve(int num)
{
        mapa.clear();
        for(int i=0; i<primos.size() && primos[i]*primos[i]<= num; i++)
                while(num%primos[i]==0)
                {
                        mapa[primos[i]]++;
                        num/=primos[i];
                }
        if(num>1)
                mapa[num]++;
//        printf("Num %d\n", num);
        long long int sol = 1;
        for(it=mapa.begin(); it!=mapa.end(); it++)
        {
                sol *= it->second +1;
                //printf("%d %d\n", it->first, it->second);
        }
        return sol;
}

int main()
{
        int nc,n1,n2;
        llenacriba();
        long long int total;
        int nsol;
        scanf("%d", &nc);
        while(nc--)
        {
                scanf("%d %d", &n1, &n2);
                total=0;
                for(int i=n1; i<=n2; i++)
                {
                        long long int tmp = solve(i);
                        if(total<tmp)
                        {
                                total=tmp;
                                nsol=i;
                        }
                }
                printf("Between %d and %d, %d has a maximum of %lld divisors.\n",n1,n2,nsol, total);
                        
        }
        
        return 0;
}
