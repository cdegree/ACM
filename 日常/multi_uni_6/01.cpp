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

const int N = 1000005;
LL pre[N],suf[N];
LL a[N],b[N];
const LL mod = 1e9+7;
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; ++i)scanf("%I64d",&b[i]);
        sort(b,b+n);
        for(int l=0,r=n-1,i=1; i<=n; ++i)
        {
            if(i&1)
            {
                a[i]=b[l++];
            }
            else
            {
                a[i]=b[r--];
            }
        }

        LL res = 1 ;
        pre[0]=1;
        for(int i=1; i<=n; ++i)
        {
            pre[i]=pre[i-1]*a[i];
            pre[i]%=mod;
            res *=a[i];
            res %=mod;
        }
        suf[n+1]=1;
        for(int i=n; i>=1; --i)
        {
            suf[i]=suf[i+1]*a[i];
            suf[i]%=mod;
        }
        for(int i=2; i<=n; ++i)
        {
            res += pre[i-2]*(a[i]*a[i-1]%mod-min(a[i],a[i-1])+mod)%mod*suf[i+1]%mod;
        }

        res %= mod;
        printf("%I64d\n",res);
    }
    return 0;
}
