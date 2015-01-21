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

LL dp[55][55];

int main()
{

    memset(dp,0,sizeof(dp));
    int n;
    for(n=5;n<=18;++n)
    {
        //scanf("%d",&n);
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
            //printf("%I64d ",dp[i][j]);
        }
        //puts("");
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            printf("%3I64d ",dp[i][j]);
        }
        puts("");
    }
    LL res=0;
    for(int i=0;i<=n;++i)
    {
        res += dp[n][i];
    }
    printf("%I64d\n",res);}
	return 0;
}
