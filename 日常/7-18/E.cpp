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

LL dp[66][(1<<16)];

bool test_bit(int mask,int pos)
{
    return (mask&(1<<pos))!=0;
}
int count_bit(int mask,int m)
{
    int ret=0;
    for(int i=0; i<m; ++i)
    {
        ret += test_bit(mask,i);
    }
    //printf("cnt = %d\n",ret);
    return ret;
}
void clear_bit(int &mask,int pos)
{
    mask &= ((1<<pos)-1);
}
void pf(int mask,int m)
{
    for(int i=0; i<m; ++i)
    {
        if(test_bit(mask,i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1; i<=n; ++i)
        {
            int b = min(i-1,m);
            for(int mask=0; mask<(1<<b); ++mask)
            {
                int nmask1=mask<<1;
                int nmask2=((mask<<1)|1);
                if(i<m)
                {
                    dp[i][nmask1] += dp[i-1][mask];
                    dp[i][nmask2] += dp[i-1][mask];
                }
                else
                {
                    if(count_bit(nmask1,m)>=k)
                    {
                        clear_bit(nmask1,m);
                        dp[i][nmask1] += dp[i-1][mask];
                    }
                    if(count_bit(nmask2,m)>=k)
                    {
                        clear_bit(nmask2,m);
                        dp[i][nmask2] += dp[i-1][mask];
                    }
                }
            }
        }
        LL sum=0;
        for(int mask=0; mask<(1<<m); ++mask)
        {
            sum += dp[n][mask];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
