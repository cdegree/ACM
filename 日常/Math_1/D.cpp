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
LL dfs(int cur,LL g,int n,LL m)
{
    LL ret=0;
    for(int i=cur;i<n;++i)
    {
        LL lcm = a[i]/__gcd(a[i],g)*g;
        ret += m/lcm - dfs(i+1,lcm,n,m);
    }
    return ret;
}
int main()
{
    LL n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;++i)cin>>a[i];
        LL res=0;
        for(int i=0;i<n;++i)
        {
            res += m/a[i] - dfs(i+1,a[i],n,m);
        }
        cout<<res<<endl;
    }
	return 0;
}
