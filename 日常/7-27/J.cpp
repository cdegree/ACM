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

const int N = 1000005;
LL dp[N],mod=1e9+7;
LL prime[N];
int len;
bool isprime[N];
void init()
{
    len=0;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=1;
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
}
int main()
{
    LL n;
    F[0]=1;
    F[1]=1;
    for(int i=2; i<N; ++i)
    {
        F[i]=F[i-1]+F[i-2];
        F[i]%=mod;
    }
    while(cin>>n)
    {

    }
    return 0;
}
