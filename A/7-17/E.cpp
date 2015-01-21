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

const int N = 405;
LL dp[N][(1<<13)];
const LL mod = 1000000007LL;

int test_bit(int mask,int pos)
{
    return ((1<<pos)&mask)!=0;
}
void clear_bit(int &mask,int pos)
{
    mask = (mask&((1<<pos)-1));
}
bool isp(int mask,int n)
{
    bool ok=true;
    for(int i=0;i<n/2;++i)
    {
        if(test_bit(mask,i)!=test_bit(mask,n-i-1))
        {
            ok=false;
            break;
        }
    }
    return ok;
}
void pf(int mask,int n)
{
    for(int i=0;i<n;++i)
    {
        if(test_bit(mask,i))
        {
            printf("1");
        }
        else printf("0");
    }
}

int main()
{
    int T;
    //printf("%d\n",isp(3,3));
    scanf("%d",&T);
    int n,k;
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(k==1)
        {
            puts("0");
        }
        else
        {
            memset(dp,0,sizeof(dp));
            dp[1][0]=dp[1][1]=1;
            for(int i=2;i<=n;++i)
            {
                int b = min(i-1,k);
                //printf("%d: b = %d\n",i,b);
                for(int mask=0;mask<(1<<b);mask++)
                {
                    if((i-1<k)||!isp(mask,b))
                    {
                        int nmask1 = mask<<1;
                        int nmask2 = (mask<<1)|1;
                        if((i<k)||(!isp(nmask1,b+1)))
                        {
                            //pf(mask,b);
                            //printf(" ---> ");
                            //pf(nmask1,b+1);puts("");
                            clear_bit(nmask1,k);
                            dp[i][nmask1]+=dp[i-1][mask];
                            dp[i][nmask1]%=mod;
                        }
                        if((i<k)||(!isp(nmask2,b+1)))
                        {
                            //pf(mask,b);
                            //printf(" ---> ");
                            //pf(nmask2,b+1);puts("");
                            clear_bit(nmask2,k);
                            dp[i][nmask2]+=dp[i-1][mask];
                            dp[i][nmask2]%=mod;
                        }
                    }
                }
            }
            LL sum = 0;
            int b = min(k,n);
            for(int mask=0;mask<(1<<b);++mask)
            {
                if(!isp(mask,b)||n<k)sum += dp[n][mask];
                sum %= mod;
            }
            printf("%lld\n",sum);
        }
    }
	return 0;
}
