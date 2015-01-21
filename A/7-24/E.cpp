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

const int N = 100005;
const int M = 1000005;

struct edge
{
    int u,v,c;
}E[M*2];


bool cmp(edge a,edge b)
{
    return a.c>b.c;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",A+i);
        }
        for(int i=0;i<m;++i)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            E[i].u=u;
            E[i].v=v;
            E[i].c=c;
        }
        sort(E,E+m,cmp);
        for(int i=0;i<m;++i)
        {

        }
    }
	return 0;
}
