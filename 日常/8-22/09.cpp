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

char s[100005];
const LL mod = 1000000007;
const LL md = 1000000006;
LL P(LL x,LL n)
{
    if(0==n)return 1;
    if(1==n)return x;
    LL ret;
    if(n&1)
    {
        ret = P(x,n-1);
        ret = x*ret%mod;
    }
    else
    {
        ret = P(x,n/2);
        ret = ret*ret%mod;
    }
    return ret;
}
int main()
{
    while(~scanf("%s",s))
    {
        int len = strlen(s);
        LL n =0;
        for(int i=0;i<len;++i)
        {
            n = (n*10+(s[i]-'0'))%md;
        }
        n = (n-1+md)%md;
        LL res = P(2,n);
        printf("%I64d\n",res);
    }
	return 0;
}
