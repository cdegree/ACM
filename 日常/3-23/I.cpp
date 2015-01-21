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

const LL mod = 1e9 + 7 ;
LL dp[5005];
LL P(LL n)
{
    LL ret = 1 ;
    for(int i=0;i<n;i++)
    {
        ret *= n ;
        ret %= mod ;
    }
    return ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            LL sum = 1;
            dp[i] = P(i) ;
            for(int j=i-1;j>0;j--)
            {
                sum *= i;
                sum %= mod ;
                dp[i] = (dp[i] - (dp[j]*sum)%mod + mod)%mod ;
            }
        }
        printf("%I64d\n",dp[n]);
    }
	return 0;
}
