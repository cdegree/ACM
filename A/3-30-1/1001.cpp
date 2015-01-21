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
using namespace std;

typedef long long LL ;
const int N = 105;
LL dp[N];
LL mod = 1e9+7;
int main()
{
    LL n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
            dp[i] %= mod;
        }
        printf("%I64d\n",dp[n]);
    }
	return 0;
}
