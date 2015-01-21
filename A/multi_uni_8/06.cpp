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
int dp[N][N],dp2[N][N];
char a[N],b[N],c[N];
int id[N];
void get_dp(int i,int j,int len)
{
    //printf("%d,%d,%d    %c,%c\n",i,j,len,a[i],b[j]);
    if(len<0)return ;
    if(c[i]==b[j])
    {
        id[len--]=j;
        --i,--j;
        get_dp(i,j,len);
    }
    else
    {
        if(dp2[i][j-1]>dp2[i-1][j])
        {
            get_dp(i,j-1,len);
        }
        else get_dp(i-1,j,len);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%s%s%s",a,b,c);
        printf("Case #%d: ",t);
        int n = strlen(a),m=strlen(b);
        int n2 = strlen(c);
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {

                if(i>0&&j>0)dp[i][j]=dp[i-1][j-1];
                if(a[i]==b[j])++dp[i][j];
                if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]);
                if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
//        for(int i=0; i<n; ++i)
//        {
//            for(int j=0; j<m; ++j)
//            {
//                printf("%d ",dp[i][j]);
//            }
//            puts("");
//        }
        for(int i=0; i<n2; ++i)
        {
            for(int j=0; j<m; ++j)
            {

                if(i>0&&j>0)dp2[i][j]=dp2[i-1][j-1];
                if(c[i]==b[j])++dp2[i][j];
                if(j>0)dp2[i][j]=max(dp2[i][j],dp2[i][j-1]);
                if(i>0)dp2[i][j]=max(dp2[i][j],dp2[i-1][j]);
            }
        }
//        for(int i=0; i<n2; ++i)
//        {
//            for(int j=0; j<m; ++j)
//            {
//                printf("%d ",dp2[i][j]);
//            }
//            puts("");
//        }
        int res = 0;
        int len = dp2[n2-1][m-1];
        for(int i=0;i<n2;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(dp2[i][j]==len&&c[i]==b[j])
                {
                    get_dp(i,j,len-1);
                    res = max(res,dp[n-1][m-1]-dp[ n-1 ][ id[len-1] ]+ dp[n-1][id[0] ]-1+len );
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
