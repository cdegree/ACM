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
const int fa=202;
const int fa1=1000001;
int n,m,l,r;
double dp[2][fa];
int x;
double a[fa];
int aa[fa1];
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("01in.txt","r",stdin);
    int j,k;
    while(1)
    {
        scanf("%d%d%d%d",&n,&m,&l,&r);
        if(n==0&&m==0&&l==0&&r==0)break;
        //dfs(1);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1; i<=m; ++i)
        {
            scanf("%d",&x);
            aa[i]=x;
        }
        int nn = n/2;
        for(int ii=1; ii<=m; ++ii)
        {
//            if(a[ii]==0)
//            {
//                for(i=0; i<n; i++)
//                dp[ii][i]=dp[ii-1][i];
//                continue;
//            }
            for(int i=0; i<=nn; ++i)dp[ii%2][i]=0;
            for(int i=0; i<=nn; ++i)
            {
                //for(j=1;j<=100;j++)
                int p = (i-aa[ii]+n)%n;
                int q = (i+aa[ii]+n)%n;
                if(p>nn) p = n - p;
                if(q>nn) q = n - q;
                dp[ii%2][i]+=dp[(ii-1)%2][p]*0.5;
                dp[ii%2][i]+=dp[(ii-1)%2][q]*0.5;

            }
        }
        double ans=0;
        if(l>r)swap(l,r);
        for(int i=n-1,j=1;i>nn;--i)
        {
            dp[m%2][i] = dp[m%2][j++];
        }
        for(int i=l-1; i<=r-1; ++i)
        {
            ans+=dp[m%2][i];
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
