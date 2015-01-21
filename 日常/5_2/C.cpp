#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;

typedef long long LL ;

int res,x,y,z;
int dp[1005][2];
int gao(int n,bool g)
{
    if(n==0)return g?-x/2:0;
    if(~dp[n][g])return dp[n][g];
    int &ret = dp[n][g];
    int c = g?z:y+x;
    ret = 1e9;
    for(int i=1;i<=n;++i)
    {
        int t1 = gao(i-1,0);
        int t2 = gao(n-i,1);
        t1 = max(t2,t1)+c;
        ret = min(ret,t1);
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    int n;
    int T;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        res=0;
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d%d",&n,&x,&y,&z);
        res = gao(n-1,0);
        printf("Case %d: %d\n",t,res);
    }
	return 0;
}
