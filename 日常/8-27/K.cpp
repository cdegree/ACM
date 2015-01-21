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

struct edge
{
    int u,v;
    double dis;
}E[2505];

struct point
{
    double x,y;
}P[55];

int Set[55];
int Find_Set(int x)
{
    if(x==Set[x])return x;
    return Set[x]=Find_Set(Set[x]);
}
void Union_Set(int x,int y)
{
    Set[Find_Set(y)]=Find_Set(x);
}
double get_dis(point a,point b)
{
    return sqrt( sqr(a.x-b.x)+sqr(a.y-b.y) );
}
bool cmp(edge a,edge b)
{
    return a.dis<b.dis;
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        int p,q;
        scanf("%d%d",&p,&q);
        for(int i=1;i<=n;++i)
        {
            scanf("%lf%lf",&P[i].x,&P[i].y);
        }
        for(int i=0;i<55;++i)Set[i]=i;
        double res=0;
        int m=0;
        for(int i=1;i<n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                E[m].u=i;
                E[m].v=j;
                E[m++].dis=get_dis(P[i],P[j]);
            }
        }
        res+=get_dis(P[p],P[q]);
        Union_Set(p,q);
        sort(E,E+m,cmp);
        for(int i=0;i<m;++i)
        {
            int x = Find_Set(E[i].u);
            int y = Find_Set(E[i].v);
            if(x==y)continue;
            res+=E[i].dis;
            Union_Set(x,y);
        }
        printf("%.2f\n",res);
    }
	return 0;
}
