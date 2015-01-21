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
using namespace std;

typedef long long LL ;

LL a,p,m,pre,mod;

LL gao(LL x,LL n)
{
    if(n==0)return 1;
    else if(n==1)return x%mod;
    else
    {
        if(n&1)
        {
            LL ret = gao(x,n-1);
            return ret*x%mod;
        }
        else
        {
            LL ret = gao(x,n/2);
            ret *= ret;
            ret %=mod;
            return ret;
        }
    }
}
int main()
{
    int T=0;
    while(cin>>p>>m)
    {
        if(T++)puts("");
        mod=1;
        for(LL i=1;i<=m;++i)
        {
            mod*=i;
        }
        LL pre=-1;
        a=p%mod;
        if(a==0){puts("0");continue;}
        while(1)
        {
            a=gao(p,a);
            if(pre==a)
            {
                break;
            }
            pre=a;
        }
        cout<<pre<<endl;
    }
	return 0;
}
