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
using namespace std;

typedef long long LL ;
LL C[555][555];
LL mod = 1000000007LL;
void init()
{
    for(int i=0;i<500;i++)
    {
        C[i][0]=1;
        C[i][i]=1;
    }
    for(int i=1;i<500;i++)
    {
        for(int j=1;j<500;j++)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            C[i][j] %= mod;
        }
    }
}
LL a[55];
bool cmp(LL x,LL y)
{
    return x>y;
}
int main()
{
    init();
    scanf("%d",&T);

    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",a+i);
        }
        sort(a,a+n,cmp);
        printf("Case %d: \n",tc);

    }
	return 0;
}
