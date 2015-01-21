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

double dp[22][202][2];

int a[202];
char s[202][5];
double p[202];
bool test_bit(int mask,int pos)
{
    return (mask&(1<<pos))!=0;
}
int get_ans(int a,int b,char c)
{
    if(c=='^')return a^b;
    if(c=='&')return a&b;
    if(c=='|')return a|b;
}
int main()
{
    int T=1,n;
    while(~scanf("%d",&n))
    {
        scanf("%d",&a[0]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=n;++i)scanf("%s",s[i]);
        for(int i=1;i<=n;++i)scanf("%lf",&p[i]);
        for(int b=0;b<=20;++b)
        {
            if(test_bit(a[0],b))
            {
                dp[b][0][1]=1;
                dp[b][0][0]=0;
            }
            else
            {
                dp[b][0][1]=0;
                dp[b][0][0]=1;
            }
            for(int i=1;i<=n;++i)
            {
                int nb = test_bit(a[i],b);

                dp[b][i][0] = dp[b][i-1][0]*p[i];
                dp[b][i][1] = dp[b][i-1][1]*p[i];
                dp[b][i][ get_ans(0,nb,s[i][0]) ] += dp[b][i-1][0]*(1-p[i]);
                dp[b][i][ get_ans(1,nb,s[i][0]) ] += dp[b][i-1][1]*(1-p[i]);

                //printf("dp[%d][%d][0]=%.6f\n",b,i,dp[b][i][0]);
                //printf("dp[%d][%d][1]=%.6f\n",b,i,dp[b][i][1]);
            }
        }
        double res=0;
        for(int b=0;b<=20;++b)
        {
            res += (1<<b)*dp[b][n][1];
            //printf("%.6f\n",dp[b][n][1]);
        }
        printf("Case %d:\n",T++);
        printf("%.6f\n",res);
    }
	return 0;
}
