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
const int N = 100005;
const int M = 200005;
bool locked[N];
bool vis[N];
int head[N],next[M*2],point[M*2];
int key[N];
int pri[N];
int nedge;
void add_edge(int u,int v)
{
    point[nedge]=v;next[nedge]=head[u];head[u]=nedge++;
}
void init()
{
    memset(head,-1,sizeof(head));
    nedge=0;
    memset(locked,0,sizeof(locked));
    memset(key,-1,sizeof(key));
    memset(vis,false,sizeof(vis));
    memset(pri,0,sizeof(pri));
}
int n,m;
bool bfs()
{
    int front=0,tail=0;
/*
    Q.push(make_pair(1,0));
    Q.push(make_pair(0,1));
    Q.push(make_pair(1,1));
    while(!Q.empty())
    {
        printf("            %d %d\n",Q.top().first,Q.top().second);
        Q.pop();
    }
*/
    set< pair<int,int> > Q;
    Q.insert(make_pair(0,0));
    locked[key[0]]=false;
    vis[0]=true;
    while(!Q.empty())
    {
        pair<int,int> cur = *(Q.begin());
        if(locked[cur.second])break;
        locked[key[cur.second]]=false;
        Q.erase(cur);
        //printf("cur = %d\n",cur.second);
        for(int e=head[cur.second];~e;e=next[e])
        {
            int v = point[e];
            //printf("v = %d\n",v);
            if(!vis[v])
            {
                vis[v]=true;
                Q.insert(make_pair(locked[v],v));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])return false;
    }
    return true;
}
void gao()
{
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            int j= i ;
            vis[i]=1;
            while(~key[j]&&!vis[key[j] ])
            {
                vis[key[j] ]=1;
                pri[ key[j] ] = pri[j] + 1 ;
                j = key[j];
            }
        }
    }
    memset(vis,false,sizeof(vis));
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        int p;
        scanf("%d",&p);
        while(p--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            locked[x]=true;
            key[y]=x;
        }
        gao();

        printf("Case #%d: ",t);
        if(bfs())
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
	return 0;
}
