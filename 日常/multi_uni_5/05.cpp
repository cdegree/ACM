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

const int N = 100005;
struct edge
{
    int u,v,pre;
}E[N*2];
int nedge,head[N],belong[N];
void add_edge(int u,int v)
{
    E[nedge].u=u;
    E[nedge].v=v;
    E[nedge].pre=head[u];
    head[u]=nedge++;
}
int n,m;
struct node
{

}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<m;++i){scanf("%d%d",&u,&v);add_edge(u,v);add_edge(v,u);}

    }
	return 0;
}
