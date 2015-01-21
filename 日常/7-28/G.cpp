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
const int N = 20000010;
bool isprime[N];
const int M = 1270609;
LL prime[M];
int len;
LL get_ans(LL n)
{
    LL ret=1;
    LL cnt;
    for(int i=0;prime[i]*prime[i]<=n;++i)
    {
        //cout<<prime[i]*prime[i]<<endl;
        cnt=0;
        while(n%prime[i]==0)
        {
            n/=prime[i];
            ++cnt;
        }
        ret*=(cnt+1);
    }
    if(n>1)ret*=2;
    return ret;
}

void init()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    len=0;
    for(int i=2;i<N;++i)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<N;j+=i)
            {
                isprime[j]=false;
            }
            prime[len++]=i;
        }
    }
    //printf("len=%d\n",len);
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
        if(n==1)
        {
            puts("1");
            continue;
        }
        LL res = get_ans(n);
        printf("%lld\n",res);
    }
	return 0;
}
