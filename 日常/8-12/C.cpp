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

int a[1005],b[1005];
char s[1005],s2[1005];
int dp[1005][11][11];
int n;
const int inf=100000000;
int main()
{
    while(~scanf("%s%s",s,s2))
    {
        int n = strlen(s);
        for(int i=0;i<n;++i)
        {
            a[i]=s[i]-'0';
            b[i]=s2[i]-'0';
        }
        for(int i=0;i<1005;++i)for(int j=0;j<11;++j)for(int k=0;k<11;++k)dp[i][j][k]=inf;
        dp[0][0][0]=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<10;++j)
            {
                for(int k=0;k<10;++k)
                {
                    int p = (b[i]-a[i]+10)%10;
                    p = (p-j+10)%10;
                    for(int j2=0;j2<=p;++j2)
                    {
                        for(int k2=0;k2<=j2;++k2)
                        {
                            dp[i+1][(k+j2)%10][k2] = min(dp[i+1][(k+j2)%10][k2],dp[i][j][k]+p);
                        }
                    }
                    int q = (10-p)%10;
                    for(int j2=0;j2<=q;++j2)
                    {
                        for(int k2=0;k2<=j2;++k2)
                        {
                            dp[i+1][(k-j2+10)%10][(10-k2)%10] = min(dp[i+1][(k-j2+10)%10][(10-k2)%10],dp[i][j][k]+q);
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[n][0][0]);
    }
	return 0;
}
