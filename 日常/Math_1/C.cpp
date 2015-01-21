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

LL Pow(LL x,LL n)
{
    LL ret;
    if(n==0)return 1;
    else if(n&1)
    {
        ret = Pow(x,n-1);
        ret = ret*x;
    }
    else
    {
        ret = Pow(x,n/2);
        ret = ret*ret;
    }
    return ret;
}
const double eps=1e-8;
LL cnt[66];
LL get_power_sum(LL n)
{
    memset(cnt,0,sizeof(cnt));
    cnt[1]=n-1;
    for(LL i=2;Pow(2,i)<=n;++i)
    {
        LL t = pow(n+0.0,1.0/i)-5;
        while(pow(t+1,1.0*i)<=n+5&&Pow(t+1,i)<=n)++t;
        cnt[i] = t-1;
    }
    for(int i=63;i>=2;--i)
    {
        for(int j=i+1;j<64;++j)
        {
            if(j%i==0)cnt[i]-=cnt[j];
        }
    }
    LL ret = cnt[1];
    for(LL i=2;i<64;++i)
    {
        ret += cnt[i]*(i-1);
    }
    return ret;
}
int main()
{
    LL a,b;
    while(1)
    {
        cin>>a>>b;
        if(a==0&&b==0)break;
        cout<<get_power_sum(b)-get_power_sum(a-1)<<endl;
    }
	return 0;
}
