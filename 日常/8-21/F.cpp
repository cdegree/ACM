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
const int N = 100005;
int dp[N];
int a[N];

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        a[0]=-2;
        dp[0][1]=0;
        dp[0][0]=0;
        for(int i=1;i<=n;++i)dp[i][0]=dp[i][1]=1e7;
        for(int i=1;i<=n;++i)
        {
            if(abs(a[i]-a[i-1])==1)
            {
                dp[i][1] = min(dp[i-1][0],dp[i][1]);
                dp[i][0] = min(dp[i][0],cnt+dp[i-1][1]);
                dp[i][0] = min(dp[i][0],cnt+dp[i-1][0]);
            }
            else
            {
                dp[i][1]=dp[i-1][1];
            }
        }
    }
	return 0;
}
