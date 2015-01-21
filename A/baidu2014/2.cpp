#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k,x,y;
long long mod = 9999991;
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%d %d %d %d %d",&n,&m,&k,&x,&y);
        long long a = n+m-2;
        long long res = 1;
        if(a>8)a=8;
        for(int i=1;i<=k;++i)
        {
            res *= a;
            res %= mod;
        }
        int ans = res;
        printf("Case #%d:\n",t);
        printf("%d\n",ans);
    }
	return 0;
}
