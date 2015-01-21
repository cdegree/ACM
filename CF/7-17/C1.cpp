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
int dp[1000006];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        dp[0]=0;
        for(int i=1;i<10;++i)dp[i]=1;
        for(int i=10; i<=n; ++i)
        {
            int dig[9];
            int m=i;
            int len=0;
            while(m>0)
            {
                dig[len++]=m%10;
                m/=10;
            }
            int mn=99999999;
            for(int j=0; j<len; ++j)
            {
                if(dig[j]!=0)mn=min(mn,dp[i-dig[j]]);
            }
            dp[i]=mn+1;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
