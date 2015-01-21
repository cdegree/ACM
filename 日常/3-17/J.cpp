#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef long long LL ;
const int N = 100005;
int isprime[N];
void gao()
{
    for(int i=2;i<N;i++)isprime[i]=0;
    for(int i=2;i<N;i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i+i;j<N;j+=i)
            {
                isprime[j]++;
            }
        }
        isprime[i]=1;
    }
}
int main()
{
    LL n;
    gao();
    while(~scanf("%lld",&n))
    {
        LL sum=0;
        for(LL i =2 ;i*i<=n;i++)
        {
            if(n%i==0)sum += isprime[i]*isprime[n/i]*2;
        }
        printf("%lld\n",sum);
    }
	return 0;
}
