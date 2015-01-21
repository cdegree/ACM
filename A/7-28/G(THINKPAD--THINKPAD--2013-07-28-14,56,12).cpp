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
#define X first
#define Y second
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")
const int N = 10000006;
bool isprime[N];
LL get_ans(LL n)
{
    LL ret=1;
    LL i;
    for(i = 2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0)
            {
                n/=i;ret*=i;
            }
        }
    }
    if(n>1)ret*=(n-1);
    return ret;
}

void init()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<N;++i)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<N;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}
int main()
{
    LL n;
    init();
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)break;
        printf("%lld ",n);
        n = 4*n-3;
        LL res = get_ans(n);
        printf("%lld\n",res);
    }
	return 0;
}
