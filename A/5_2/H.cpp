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
LL dp[66];
int main(int argc, char const *argv[])
{
    int T=0;
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<61;++i)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        printf("Case %d: %lld\n",++T,dp[n]);
    }
	return 0;
}
