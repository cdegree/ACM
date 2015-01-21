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
const int N = 200005;
int Set[N];
LL cnt[N],val[N];
int Find_Set(int x)
{
    if(x==Set[x])return x;
    return Set[x]=Find_Set(Set[x]);
}
void Union_Set(int x,int y)
{
    Set[Find_Set(y)]=Find_Set(x);
}
struct edge
{
    int u,v;
    LL w;
}E[N];
bool cmp(edge a,edge b)
{
    return a.w>b.w;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i)Set[i]=i,cnt[i]=1,val[i]=0;
        LL res=0;
        for(int i=0;i<n-1;++i)
        {
            scanf("%d%d%I64d",&E[i].u,&E[i].v,&E[i].w);
        }
        sort(E,E+n-1,cmp);
        for(int i=0;i<n-1;++i)
        {
            LL w = E[i].w;
            int x = Find_Set(E[i].u);
            int y = Find_Set(E[i].v);
            LL sum1 = cnt[x]*w;
            LL sum2 = cnt[y]*w;
            LL val1 = val[y];
            LL val2 = val[x];
            if(sum1+val1>=sum2+val2)
            {
                cnt[y]+=cnt[x];
                Union_Set(y,x);
                val[y]=sum1+val1;
            }
            else
            {
                cnt[x]+=cnt[y];
                Union_Set(x,y);
                val[x]=sum2+val2;
            }
        }
        printf("%I64d\n",val[Find_Set(1)]);
    }
	return 0;
}
