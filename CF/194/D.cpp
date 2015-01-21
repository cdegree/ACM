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
const int N=1005;
struct edge
{
    int u,v,pre;
} E[N*N];
int n,m;

vector<pair<int,int> > vp;
int mt[N][N];
int row[N],col[N];
int cnt;
int head[N*4];
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
bool vis[N*4];
int main()
{
    while(cin>>n>>m)
    {
        int u,v;
        vp.clear();
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(mt,0,sizeof(mt));
        memset(vis,false,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            mt[u][v]=1;
        }
        for(int i=1; i<=n; ++i)
        {
            bool ok=true;
            for(int j=1; j<=n; ++j)
            {
                if(mt[i][j]==1)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)row[i]=1;
        }
        for(int j=1; j<=n; ++j)
        {
            bool ok=true;
            for(int i=1; i<=n; ++i)
            {
                if(mt[i][j]==1)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                col[j]=1;
            }
        }
        for(int i=2; i<n; ++i)
        {
            add_edge(i,i+n);
            add_edge(i+n,i);
            add_edge(i+2*n,i+3*n);
            add_edge(i+3*n,i+2*n);
        }
        int cnt=0;
        for(int i=2; i<n; ++i)
        {
            if(row[i]&&!vis[i])
            {
                ++cnt;
                vis[i]=1;
            }
            if(vis[i]&&col[i]&&!vis[n-i+1])
            {
                vis[n-i+1]=1;
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
