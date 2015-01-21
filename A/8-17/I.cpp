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
int a[N];
int res;
int dp[N][4];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; ++i)scanf("%d",a+i);
        res=0;
        memset(dp,0,sizeof(dp));
        if(a[0]==1)dp[0][1]=1,dp[0][2]=1;
        else if(a[0]==2)dp[0][3]=1;
        else if(a[0]==0)dp[0][0]=1;

        for(int i=1;i<n;++i)
        {
            if(a[i]==1)dp[i][0]+=dp[i-1][2],dp[i][2]+=dp[i-1][1],dp[i][1]+=dp[i-1][0];
            else if(a[i]==2)dp[i][1]+=dp[i-1][2],dp[i][3]+=dp[i-1][1],dp[i][2]+=dp[i-1][3];
            else if(a[i]==0)dp[i][0]+=dp[i-1][0];
            else dp[i][3]+=dp[i-1][3];
        }
        res = dp[n-1][0]+dp[n-1][2];
        printf("%d\n",res);
    }
    return 0;
}
