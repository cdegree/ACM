#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 2002;
LL dp[N][N];
LL mod = 1000000007;
int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=2000;++i)
    {
        dp[1][i]=1;
    }
    for(int i=1;i<2000;++i)
    {
        for(int j=1;j<=2000;++j)
        {
            for(int k=j;k<=2000;k+=j)
            {
                dp[i+1][k]+=dp[i][j];
                dp[i+1][k]%=mod;
            }
        }
    }
    int n,k;
    while(cin>>n>>k)
    {
        LL res = 0;
        for(int i=1;i<=n;++i)
        {
            res += dp[k][i];
            res %= mod;
        }
        cout<<res<<endl;
    }
	return 0;
}
