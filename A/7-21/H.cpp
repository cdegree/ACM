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

const int N = 50005;
const int M = 200005;
struct edge
{
    int u,v,id;
    LL c;
    bool bol;
}E[M];
int head[N],cnt;

void add_edge(int u,int v,int id,LL c)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].id=id;
    E[cnt].bol=false;
    E[cnt++].c=c;
}
bool cmp1(edge a,edge b)
{
    return a.c>b.c;
}
bool cmp2(edge a,edge b)
{
    return a.c<b.c;
}
int Set[M];
int Find_Set(int x)
{
    if(Set[x]==x)return x;
    return Set[x]=Find_Set(Set[x]);
}
void Union_Set(int x,int y)
{
    Set[Find_Set(x)]=Find_Set(y);
}
int res[M];
int main()
{
    int n,m;
    LL s;
    int T=0;
    while(cin>>n>>m>>s)
    {
        if(T!=0)puts("");
        T++;
        for(int i=1;i<=m;++i)Set[i]=i;
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=1;i<=m;++i)
        {
            int u,v;
            LL c;
            scanf("%d %d %lld",&u,&v,&c);
            add_edge(u,v,i,c);
        }
        sort(E,E+m,cmp1);
        int len=0;
        for(int i=0;i<m;++i)
        {
            int x=E[i].u;
            int y=E[i].v;
            if(Find_Set(x)==Find_Set(y))
            {
                continue;
            }
            else
            {
                E[i].bol=true;
                Union_Set(x,y);
            }
        }
        sort(E,E+m,cmp2);
        for(int i=0;i<m;++i)
        {
            if(!E[i].bol&&E[i].c<=s)
            {
                s-=E[i].c;
                res[len++]=E[i].id;
            }
        }
        printf("%d\n",len);
        for(int i=0;i<len;++i)
        {
            printf("%d%c",res[i],i==len-1?'\n':' ');
        }
    }
	return 0;
}
