#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define ll long long
#pragma comment(linker,"/STACK:102400000,102400000")
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int ma=1e+9;
const int fa=512;
int n,m;
int x,y;
int minc;
int d[fa];
bool bo[fa];
int a[fa][fa];
int head[fa],tot;
struct wgh
{
    int y,w;
    int ne;
} ed[fa*fa];
int v;
void jian(int x,int y,int w)
{
    tot++;
    ed[tot].ne=head[x];
    ed[tot].w=w;
    ed[tot].y=y;
    head[x]=tot;
}
int pre[fa];
void bfs(int u)
{
    int i,j,k;
    bo[u]=true;
    queue<int>q;
    for(i=0; i<n; i++)d[i]=ma;
    for(i=0; i<n; i++)pre[i]=-1;
    while(!q.empty())q.pop();
    q.push(u);
    bo[u]=true;
    d[u]=0;
    bool boo=false;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x]; ~i; i=ed[i].ne)
        {
            if(ed[i].y!=pre[x])
            {
                int y=ed[i].y;
                int w=ed[i].w;
                if(!bo[y])
                {
                    bo[y]=true;
                    d[y]=1+d[x];
                    pre[y]=x;
                    q.push(y);
                }
                else
                {
                    boo=1;
                    minc=min(minc,d[x]+d[y]);
                    break;
                }
            }
        }
        if(boo)break;
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
#endif
    int t,i,j,k,T=0;
    scanf("%d",&t);
    while(t--)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&x,&y);
            if(a[x][y])continue;
            a[x][y]=a[y][x]=1;
            jian(x,y,1);
            jian(y,x,1);
        }
        minc=ma;
        for(i=0; i<n; i++)
        {
            v=i;
            memset(bo,0,sizeof(bo));
            bfs(i);
        }
        if(minc<ma)
            printf("Case %d: %d\n",++T,minc+1);
        else
            printf("Case %d: impossible\n",++T);
    }
    return 0;
}
