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

using namespace std;

typedef long long LL ;

const int N = 200005;
LL a[N];
LL n;
LL dp[N][2];
bool vis[N][2];

LL gao(int x,int d)
{
    //printf("pos = %d dir = %d\n",x,d);
    if(vis[x][d])return dp[x][d];
    vis[x][d] = true ;
    LL ret ;
    if(d==1)
    {
        if(a[x]+x>n)
        {
            ret = a[x] ;
        }
        else
        {
            ret = gao(a[x]+x,!d);
            if(~ret)ret += a[x];
        }
    }
    else
    {
        if(x-a[x]<=0)
        {
            ret = a[x] ;
        }
        else
        {
            ret = gao(x-a[x],!d);
            if(~ret)ret += a[x];
        }
    }
    return dp[x][d] = ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=2; i<=n; i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    memset(vis,false,sizeof(vis));

    for(int i =1; i<n; i++)
    {
        LL res = gao(i+1,0);
        if(~res)res += i;
        cout<<res<<endl;
    }
    return 0;
}
