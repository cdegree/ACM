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
const LL mod=1000000009LL;

LL P(LL x,LL n)
{
    if(n==0)return 1;
    if(n==1)return x;
    if(n&1)
    {
        LL ret= x*P(x,n-1)%mod;
        return ret;
    }
    else
    {
        LL ret= P(x,n/2);
        ret *=ret;
        ret%=mod;
        return ret;
    }
}

LL cal(LL n,LL k)
{
    LL cnt = n/k;
    LL ret=0;
    if(cnt>0)
    {
        ret = 2*k*( (P(2,cnt)-1+mod)%mod )%mod;
    }
    ret += n%k;
    ret%=mod;
    return ret;
}
int main()
{
    LL n,m,k;
    while(cin>>n>>m>>k)
    {
        LL q = n-m;
        LL l=0,r=1000000000LL,mid,ans=0;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(mid>q)
            {
                r=mid-1;
            }
            else if(k*mid<=n)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        LL res = 0;
        q -=ans;
        //cout<<res<<endl;
        if(q>0)
        {
            res = m;
        }
        else
        {
            LL u = m-ans*(k-1);
            //cout<<u<<endl;
            res += cal(u,k);
            res %= mod;
            res += ans*(k-1);
            res %=mod;
        }
        res%=mod;
        cout<<res<<endl;
    }
	return 0;
}
