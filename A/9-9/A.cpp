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
    int x=0;
    for(int i=0;i<10;++i)
    {
        mp[i]=x++;
        if(i==3||i==8)--x;
        //printf("mp[%d]=%d\n",i,mp[i]);
    }
}
LL gao(LL n)
{
    LL ret=0,e=1;
    while(n>0)
    {
        ret += mp[(n%10)]*e;
        e*=8;
        n/=10;
    }
    return ret;
}
int main()
{
    LL n;
    init();
    while(~scanf("%I64d",&n),n)
    {
        printf("%I64d: %I64d\n",n,gao(n));
    }
	return 0;
}
