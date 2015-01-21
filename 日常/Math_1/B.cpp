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

LL a[11];
LL dfs(int cur,int m,LL gcd,LL n)
{
    LL ret = 0;
    for(int i=cur; i<m; ++i)
    {
        if(a[i]!=0)
        {
            LL lcm = gcd*a[i]/__gcd(a[i],gcd);
            ret += n/lcm - dfs(i+1,m,lcm,n);
        }
    }
    return ret;
}
int main()
{
    LL n,m;
    while(cin>>n>>m)
    {
        for(int i=0; i<m; ++i)cin>>a[i];
        --n;
        LL res = 0;
        for(int i=0; i<m; ++i)
        {
            if(a[i]!=0)res += n/a[i] - dfs(i+1,m,a[i],n);
        }
        cout<<res<<endl;
    }
    return 0;
}
