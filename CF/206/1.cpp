#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}


const int N = 100005;
int w[N],sum[N];
int main()
{
    int n,l,r,Ql,Qr;
    while(~scanf("%d%d%d%d%d",&n,&l,&r,&Ql,&Qr))
    {
        sum[0]=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",w+i);
            sum[i]=sum[i-1]+w[i];
        }
        LL res=1e15;
        for(int i=0;i<=n;++i)
        {
            int sumL = sum[i]*l;
            int sumR = (sum[n]-sum[i])*r;
            int ex = abs((n-i)-i);
            ex = max(ex-1,0);
            if(n-i>i)ex*=Qr;
            else ex*=Ql;
            LL tmp = sumL+sumR+ex;
            checkmin(res,tmp);
        }
        printf("%I64d\n",res);
    }
	return 0;
}
