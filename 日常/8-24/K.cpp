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

int dp[3003][3003];

int a[3003],b[3003];
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=n;++i)scanf("%d",b+i);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;++i)
        {
            if( (a[i]==b[i]&&a[i+1]==b[i+1])||(a[i]==b[i+1]&&a[i+1]==b[i]) )
            {
                dp[i][2]=1;
            }
        }
        for(int i=3;i<n;++i)
        {
            for(int j=1;j+i<=n;++j)
            {
                if(dp[j][i-1]&&a[j+i]==b[j+i])
                {
                    dp[j][i]=1;
                }
                else if(dp[j+1][i-1]&&a[j]==b[j])
                {
                    dp[j][i]=1;
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)res+=dp[i][j];
        printf("%d\n",res);
    }
	return 0;
}
