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

LL get_ans(LL n,LL a,LL b)
{
    LL ret=0;
    for(LL i =0;i<n;++i)
    {
        ret += abs( i%a - i%b );
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL n,a,b;
        scanf("%I64d %I64d %I64d",&n,&a,&b);
        LL lcm = a*b/__gcd(a,b);
        if(n<=lcm)
        {
            printf("%I64d\n",get_ans(n,a,b));
        }
        else
        {
            LL cnt=n/lcm;
            LL res = get_ans(lcm,a,b)*cnt+get_ans(n%lcm,a,b);
            printf("%I64d\n",res);
        }

    }
	return 0;
}
