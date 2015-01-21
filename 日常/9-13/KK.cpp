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
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int ma=1e+9;
const int fa=112;
const int fa1=1e+4+1;
int n,m,t,tot,ans;
int a[fa];
int mp[15*fa1];
int bo[fa],l;
struct wgh
{
    int x;
    bool b;
};
bool v[1222][1222];
bool v1[1222][1222];
int mod=1007;
int mod1=1009;
int aa[4];
void dfs(int u,int aa,int b,int c,int sum)
{
    if(aa+b+sum<=c)return;
    if(aa+sum<b)return;
    if(aa+sum<c)return;
    if(aa+c+sum<=b)return;
    if(b+sum<c)return;
    if(b+c+sum<=aa)return;
    if(u>n)
    {
        int a1[3];
        a1[0]=aa;
        a1[1]=b;
        a1[2]=c;
        sort(a1,a1+3);
        int a=a1[0];
        int b=a1[1];
        int c=a1[2];
        if(v[a%mod][b%mod]==false&&v1[a%mod1][b%mod1]==false)
        {
            v[a%mod][b%mod]=true;
            v1[a%mod1][b%mod1]=true;
            ans++;
        }
        return;
    }
    dfs(u+1,aa+a[u],b,c,sum-a[u]);
    dfs(u+1,aa,b+a[u],c,sum-a[u]);
    dfs(u+1,aa,b,c+a[u],sum-a[u]);
}
void dfs1(int u)
{
    if(u>n)
    {
        int o=0,i;
        for(i=1; i<=n; i++)
            if(bo[i])
                o+=a[i];
        if(mp[o]==0)mp[o]=++tot;
        return;
    }
    bo[u]=1;
    dfs1(u+1);
    bo[u]=0;
    dfs1(u+1);
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0; i<15*fa1; i++)
        {
            mp[i]=0;
        }
        memset(v,0,sizeof(v));
        memset(v1,0,sizeof(v1));
        tot=0;
        scanf("%d",&n);
        ans=0;
        l=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(mp[a[i]]==0)
                mp[a[i]]=++tot;
            l+=a[i];
        }
        int aa[5];
        memset(aa,0,sizeof(aa));
        sort(a+1,a+1+n,cmp);
        dfs1(1);
        dfs(1,0,0,0,l);
        printf("%d\n",ans);
    }
    return 0;
}
