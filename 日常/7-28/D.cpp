#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define ll long long
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int fa=1100;
int n,m,ans1,ans2,ans;
int dp1[2][fa];
int dp2[2][fa];
int a[fa];
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        ans=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(a[j]>=a[i])
                dp1[1][i]=max(dp1[1][i],dp1[1][j]);
                if(a[j]>a[i])
                dp1[0][i]=max(dp1[0][i],dp1[1][j]);
            }
            dp1[1][i]++;
            dp1[0][i]++;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(a[j]<=a[i])
                dp2[1][i]=max(dp2[1][i],dp2[1][j]);
                if(a[j]<a[i])
                dp2[0][i]=max(dp2[0][i],dp2[1][j]);
            }
            dp2[1][i]++;
            dp2[0][i]++;
        }
        for(i=1;i<=n;i++)
        {
            //ans=max(dp1[0][i]+dp2[1][i]-1,ans);
        }
        memset(dp1,0,sizeof(dp1));memset(dp2,0,sizeof(dp2));
        ans1=ans2=0;
        for(i=n;i>=1;i--)
        {
            for(j=n;j>i;j--)
            {
                if(a[j]>=a[i])
                dp1[1][i]=max(dp1[1][i],dp1[1][j]);
                if(a[j]>a[i])
                dp1[0][i]=max(dp1[0][i],dp1[1][j]);
            }
            dp1[1][i]++;
            dp1[0][i]++;
        }
        for(i=n;i>=1;i--)
        {
            for(j=n;j>i;j--)
            {
                if(a[j]<=a[i])
                dp2[1][i]=max(dp2[1][i],dp2[1][j]);
                if(a[j]<a[i])
                dp2[0][i]=max(dp2[0][i],dp2[1][j]);
            }
            dp2[1][i]++;
            dp2[0][i]++;
        }
        for(i=1;i<=n;i++)
        {
            ans=max(dp1[0][i]+dp2[1][i]-1,ans);
        }
        //ans=max(ans1+ans2,ans);
        printf("%d\n",ans);
    }

    return 0;
}
