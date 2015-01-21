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


int mp[11];
void init()
{
    int j=0;
    for(int i=0;i<10;++i)
    {
        mp[i]=j;
        if(i==3||i==8);
        else ++j;
    }
}

LL gao(LL n)
{
    LL e=1;
    LL sum=0;
    while(n)
    {
        sum += mp[n%10]*e;
        e*=8;
        n/=10;
    }
    return sum;
}
int main()
{
    LL n;
    init();
    while(~scanf("%I64d",&n),n)
    {
        LL m;
        m = gao(n);
        printf("%I64d: %I64d\n",n,m);
    }
	return 0;
}
