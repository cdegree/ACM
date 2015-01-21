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

LL n,k;
LL mod = 1e9+7;
LL dp[1000006][4];
int main()
{
    while(~scanf("%I64d%I64d",&n,&k))
    {
        LL r = n/2;
        n = n*n/2;

        LL res = 0;

        for(LL i=0;i<=r;++i)
        {
            for(LL j=0;j<=r;++j)
            {
                LL rest = k-i-j;
                printf("%I64d %I64d %I64d\n",i,j,rest);
                rest*=4;
                rest%=mod;
                if(rest==0)rest=1;
                if(i)rest*=3*i;
                rest%=mod;
                if(j)rest*=3*j;
                rest%=mod;
                res+=rest;
            }
        }


        printf("%I64d\n",res);
    }
	return 0;
}
