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

LL n;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        LL m = n;
        if(n&1)
        {
            n/=2;
            printf("%I64d\n",max(n*(n+1),m-1));
        }
        else
        {
            n/=2;
            LL res=m-1;
            for(LL i=n;i>=max(n-20,1LL);--i)
            {
                res=max(res,i/__gcd(i,m-i)*(m-i));
            }
            printf("%I64d\n",res);
        }
    }
	return 0;
}
