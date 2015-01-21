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

const int N = 1005;
int dp[N][N];
int mod = 10007;
char s[N];

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%s",s);
        printf("Case %d: ",t);
        int len = strlen(s);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<len;++i)
        {
            dp[i][i]=1;
            if(i+1<len)
            {
                dp[i][i+1]=2;
                if(s[i]==s[i+1])++dp[i][i+1];
            }
        }
        for(int l=2;l<len;++l)
        {
            for(int i=0;i+l<len;++i)
            {
                dp[i][i+l]=(dp[i][i+l-1]+dp[i+1][i+l]-dp[i+1][i+l-1]+mod)%mod;
                if(s[i]==s[i+l])
                {
                    dp[i][i+l] += dp[i+1][i+l-1]+1;
                }
                dp[i][i+l]%=mod;
            }
        }
        printf("%d\n",dp[0][len-1]);
    }

	return 0;
}
