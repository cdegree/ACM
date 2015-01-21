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
ll n,m;
const ll ma=1e+9;
const ll fa=1e+6+12;
char c[fa];
string s;
ll h1[111],h2[111];
int a1[fa],l;
int a2[fa];
ll sum1[5];
ll sum2[5];
ll aa[332];
ll x,y,ans,mod=1e+8+7;
ll dp1[fa];
ll dp2[fa];
ll Ext_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0) { x=1, y=0; return a; }
    ll d= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return d;
}
ll Inv(ll a,ll m)
{
    ll d,x,y;
    d= Ext_gcd(a,(ll)m,x,y);
    if(d==1) return (x%m+m)%m;
    return -1;
}
ll nv1,nv2;
int main()
{
    //freopen("5in.txt","w",stdout);
    freopen("5in.txt","r",stdin);
    ll i,j,k;
    nv1=Inv(31,mod);
    nv2=Inv(37,mod);
    dp1[1]=1;
    dp2[1]=1;
    for(i=2;i<fa;i++)
    {
        dp1[i]=dp1[i-1]*31%mod;
        dp2[i]=dp2[i-1]*37%mod;
    }
    for(i=0; i<26; i++)
        h1[i]=(i+1)%mod;
    for(i=0; i<26; i++)
        h2[i]=(i+1)%mod;
    while(~scanf("%I64d",&n))
    {
        for(int ii=1; ii<=n; ii++)
        {
            ans=0;
            scanf("%s",c);
            s=c;
            m=s.size();
            for(i=1; i<=m; i++)
            {
                a1[i]=h1[s[i-1]-'a'];
                a2[i]=h2[s[i-1]-'a'];
            }
            l=m/3;
            memset(sum1,0,sizeof(sum1));
            memset(sum2,0,sizeof(sum2));
            for(j=1; j<=l; j++)
            {
                sum1[0]+=a1[j]*dp1[j];
                sum2[0]+=a2[j]*dp2[j];
                sum1[0]%=mod;
                sum2[0]%=mod;
            }
            x=l;
            int xx=l;
            for(j=m; j>=m-l+1; j--)
            {
                sum1[3]+=a1[j]*dp1[xx];
                sum2[3]+=a2[j]*dp2[xx];
                sum1[3]%=mod;
                sum2[3]%=mod;
                xx--;
            }
            y=m-l+1;
            while(x)
            {
                ll o1=0,o2=0,oo;
                if(sum1[0]==sum1[3]&&sum2[3]==sum2[0])
                {
                    for(i=1; i<=x; i++)
                    {
                        o1+=a1[y-i]*dp1[i];
                        o2+=a2[y-i]*dp2[i];
                        o1%=mod;
                        o2%=mod;
                    }
                    oo=y-x-1;
                    if(o1==sum1[0]&&o2==sum2[0])
                    {
                        ans=x;
                        break;
                    }
                    while(oo!=x)
                    {
                        o1=(o1-a1[oo+x]+mod)*31%mod+a1[oo];
                        o2=(o2-a2[oo+x]+mod)*37%mod+a2[oo];
                        o1%=mod;
                        o2%=mod;
                        if(o1==sum1[0]&&o2==sum2[0])
                        {
                            ans=x;
                            break;
                        }
                        oo--;
                    }
                }
                sum1[0]-=a1[x]*dp1[x];
                sum1[0]=(sum1[0]+mod*ma)%mod;
                sum1[3]-=a1[y];
                sum1[3]=(sum1[3]%(31*mod))/31;

                sum2[0]-=a2[x]*dp2[x];
                sum2[0]=(sum2[0]+mod*ma)%mod;
                sum2[3]-=a2[y];
                sum2[3]=(sum2[3]%(37*mod))/37;
                //sum2[3]=sum2[3]*nv2%mod;
                x--;
                y++;
                if(ans)
                    break;
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
