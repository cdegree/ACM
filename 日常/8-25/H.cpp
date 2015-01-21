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

LL dp0[1005][1005],dp1[1005][1005];

int main()
{
    LL n,m,k;
    while(cin>>n>>m>>k)
    {
        memset(dp0,0,sizeof(dp0));
        dp0[0][1]=1;
        for(int i=0;i<k;++i)
        {
            for(int j=0;j<=n;++j)
            {
                for(int p=j;p<=n;++p)
                {
                    dp1[p][]
                }
            }
        }
    }
	return 0;
}
