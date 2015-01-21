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

LL mod = 1000000007LL;
LL P(LL x,LL n)
{
    if(n==0)return 1;
    if(n==1)return x%mod;
    if(n&1)
    {
        LL ret = P(x,n-1);
        ret *=x;
        ret %=mod;
        return ret;
    }
    else
    {
        LL ret = P(x,n/2);
        ret *=ret;
        ret %= mod;
        return ret;
    }
}
int main()
{
    int T;
    cin>>T;
    //while(cin>>T)cout<<P(2,T)<<endl;
    while(T--)
    {
        LL n,k;
        cin>>n>>k;
        LL m = n-k;
        if(m<2)
        {
            if(m<0)cout<<0<<endl;
            else if(m==0)cout<<1<<endl;
            else if(m==1)cout<<2<<endl;
        }
        else
        {
            LL res = P(2LL,m-2);
            res = res * (m+3);
            res %= mod;
            cout<<res<<endl;
        }
    }
	return 0;
}
