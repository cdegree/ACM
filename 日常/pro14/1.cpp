#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
LL dp[105];

const LL mod = 1e9+7;
int main()
{
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=100;++i)
    {
        dp[i]=(dp[i-1]+dp[i-2])*(i-1);
        dp[i]%=mod;
    }
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        int n;
        scanf("%d",&n);
        LL res=1;
        for(int i=0;i<n;++i)
        {
            LL a;
            scanf("%lld",&a);
            res *=a;
            res%=mod;
        }
        res = res*dp[n]%mod;
        printf("Case %d: ",t);
        printf("%lld\n",res);
    }
	return 0;
}
