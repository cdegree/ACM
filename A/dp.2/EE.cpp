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
const int fa=1e+4+112;
ll n,m;
ll g,l,t;
ll tot;
ll a[fa];
ll b[fa],ans;
bool bo[fa*100];
ll cd[1000][1000];
map<ll,ll>mp;
ll hash[20000];
ll gcd(ll a,ll b)
{
    while(b)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int ccnt=0;
void dfs(ll u,ll o,ll o1)
{
    if(u>3)
    {
        if(o==2)
        {
            if(o1==1)
                {ans++;
            cout<<ans<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<endl;
            }
        }
        return;
    }
    for(ll i=1; i<=tot; i++)
    {
        b[u]=a[i];

        if(cd[o][i]==0)continue;
        ll p=a[o]/a[cd[o][i]]*a[i];
        p=hash[p%10007];
        if(p==0)continue;
        if(u==1)
            dfs(u+1,p,i);
        else
            dfs(u+1,p,cd[o1][i]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
#endif
    ll i,j,k;
    scanf("%I64d",&t);
    //cout<<gcd(12,3)<<endl;
    //cout<<gcd(8,12)<<endl;
    while(t--)
    {

        tot=0;
        ans=0;
        //memset(bo,0,sizeof(bo));
        memset(hash,0,sizeof(hash));
        //mp.clear();
        scanf("%I64d%I64d",&g,&l);
        memset(cd,0,sizeof(cd));
        if(l%g!=0)
        {
            printf("0\n");
            continue;
        }
        g=l/g;
        for(i=1; i<=(ll)sqrt(double(g)); i++)
        {
            if(g%i==0)
            {
                tot++;
                a[tot]=i;
                tot++;
                a[tot]=g/i;
            }
        }
        if(g==(ll)sqrt(double(g))*(ll)sqrt(double(g)))
        {
            tot--;
            //a[tot]=(ll)sqrt(double(g));
        }
        //cout<<tot<<endl;
        for(i=1;i<=tot;i++)
        hash[a[i]%10007]=i;
        for(i=1;i<=tot;i++)
        for(j=i;j<=tot;j++)
        {
            ll o=gcd(a[i],a[j]);
            for(ll ii=1;ii<=tot;ii++)
            if(o==a[ii])
            {
                cd[i][j]=cd[j][i]=ii;
                break;
            }
        }
        ccnt=0;
        dfs(1,1,1);
        printf("ccnt = %d\n",ccnt);
        printf("%I64d\n",ans);
    }
    return 0;
}
