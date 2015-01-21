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

LL dp[55][11][505];
void init()
{
    memset(dp,0,sizeof(dp));
    for(int i=0; i<10; ++i)
    {
        dp[0][i][i]=1;
    }
    for(int i=1; i<55; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            for(int p=0; p<10; ++p)
            {
                for(int k=j; k<505; ++k)
                {
                    dp[i][j][k] += dp[i-1][p][k-j];
                }
            }
        }
    }
}
int main()
{
    int n,s;
    init();
    while(~scanf("%d%d",&n,&s))
    {
        if(s&1)
        {
            puts("0");
        }
        else
        {
            LL res =0;
            s/=2;
            for(int i=0; i<10; ++i)res+=dp[n-1][i][s];
            res *=res;
            printf("%lld\n",res);
        }
    }
    return 0;
}
