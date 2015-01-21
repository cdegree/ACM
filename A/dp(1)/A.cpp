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
const int N = 1005;
int dp[N][N],dp2[N][N];
char s1[N],s2[N];

int main()
{
    while(true)
    {
        int K;
        scanf("%d",&K);
        if(K==0)break;
        scanf("%s%s",s1+1,s2+1);
        int n1 = strlen(s1+1);
        int n2 = strlen(s2+1);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n1; ++i)
        {
            for(int j=1; j<=n2; ++j)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]++;
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        for(int i=1; i<=n1; ++i)
        {
            for(int j=1; j<=n2; ++j)
            {
                dp2[i][j]=0;
                if(dp[i][j]>=K)
                {
                    dp2[i][j] = dp2[i-K][j-K] + K ;
                }
                if(dp[i][j]>K)
                {
                    dp2[i][j] = max(dp2[i][j],dp2[i-1][j-1] + 1);
                }
                dp2[i][j] = max(dp2[i][j], max(dp2[i-1][j],dp2[i][j-1]));
            }
        }
/*
        for(int i=0; i<=n1; i++)
        {
            for(int j=0; j<=n2; j++)
            {
                printf("%4d",dp[i][j]);
            }
            puts("");
        }
        puts("");
        for(int i=0; i<=n1; i++)
        {
            for(int j=0; j<=n2; j++)
            {
                printf("%4d",dp2[i][j]);
            }
            puts("");
        }
*/
        printf("%d\n",dp2[n1][n2]);
    }
    return 0;
}
