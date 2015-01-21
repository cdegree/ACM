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
#pragma comment(linker,"/STACK:102400000,102400000")
#define FOR( i, a, b ) for(ll i = a; i <= b; ++i )
const ll ma=1e+9;
const ll fa=80000+112;
ll n,m;
ll prime[fa],tot=0;
ll dp[fa][2][4];
bool bo[fa];
struct wgh
{
    ll x,y;
};
wgh v[fa];
void zs()
{
    ll i,j,k;
    memset(bo,0,sizeof(bo));

    for(i=2;i<fa;i++)
    {
        if(bo[i]==false)
        {
            tot++;
            prime[tot]=i;
            for(j=i+i;j<fa;j+=i)
            {
                bo[j]=true;
            }
        }
    }
}
ll dp1[fa][2][4];
ll mod=1000000007;
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    ll i,j,k;
    zs();
    bo[0]=bo[1]=1;
    //cout<<tot<<endl;
    for(i=1;i<=tot;i++)
    {
        for(j=i;j<=tot;j++)
        {
            k=prime[i]*prime[j];
            if(k<fa)
            {
                v[k].x=prime[i];
                v[k].y=prime[j];
            }
            else break;
        }
    }
    memset(dp,0,sizeof(dp));
    //cout<<tot<<endl;
    for(i=1;i<fa;i++)
    {
        if(bo[i]==false)
        dp[i][0][1]=1;
    }
    for(i=1;i<=tot;i++)
    {
        for(j=i;j<=tot;j++)
        {
            if(prime[i]*prime[j]<fa)
            {
                dp[prime[i]*prime[j]][0][2]+=dp[prime[i]][0][1]*dp[prime[j]][0][1]%mod;
            }
            else
            {
                break;
            }
        }
    }
    for(i=1;i<=tot;i++)
    {
        for(j=i+1;j<=tot;j++)
        {
            if(prime[i]+prime[j]<fa)
            {
                dp[prime[i]+prime[j]][1][2]+=dp[prime[i]][0][1]*dp[prime[j]][0][1]%mod;
            }
            else
            {
                break;
            }
        }
    }
    //cout<<tot<<endl;
    int mm;
    while(~scanf("%d",&mm))
    {
        n=mm;
        ll ans=0;
        bool flag=false;
        for(i=1;i<=tot;i++)
        if(n%prime[i]==0)
        {
            mm=n/prime[i];
            if(dp[mm][0][2])
            {
                flag=true;
                break;
            }
        }
        if(flag)
        ans++;
        ll o=0;
        for(i=1;i<=tot;i++)
        {
            mm=n-prime[i];
            if(mm<0)break;
            if(mm%2==0&&bo[mm/2]==false)
            {
                ans++;
            }
        }
        for(i=1;i<=tot;i++)
        {
            mm=n-prime[i];
            if(mm<0)break;
                ans+=dp[mm][0][2];
                ans%=mod;
        }
        //if(n%3==0&&bo[n/3]==false)ans++;
        if(n%2==0&&bo[n/2]==false)ans++;
        ans+=dp[n][1][2];
        if(dp[n][0][2])
        ans++;
        ans+=(!bo[n]);
        ll u=0;
        for(i=1;i<=tot;i++)
        {
            mm=n-prime[i];
            if(mm<0)break;
            if(dp[mm][1][2]==0)continue;
            if(mm-prime[i]<0||bo[mm-prime[i]]==true)
            {
                u+=dp[mm][1][2];
            }
            else
            {
                u+=dp[mm][1][2]-1;
            }
        }
        ans %=mod;
        ans+=u/3;

        cout<<ans%mod<<endl;
    }
    return 0;
}
