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

bool mt[555][555];
bool vis[555];
int cntn=0;
int n;
void dfs2(int u)
{
    ++cntn;
    vis[u]=1;
    for(int i=0;i<n;++i)
    {
        if(!vis[i]&&mt[u][i])
        {
            dfs2(i);
        }
    }
}

bool use[555];
pair<int,int> add(pair<int,int> p)
{
    ++(p.second);
    if(p.second>=n)
    {
        ++(p.first);
        p.second=0;
    }
    while(p.second<=p.first)++(p.second);
    return p;
}
bool connected(int m)
{
    memset(mt,0,sizeof(mt));
    pair<int,int> p = make_pair(0,1);
    for(int i=0;i<m;++i)
    {
        if(use[i])
        {
            mt[ p.first ][ p.second ]=1;
            mt[ p.second ][ p.first ]=1;
        }
        p = add(p);
    }
    memset(vis,0,sizeof(vis));
    cntn=0;
    dfs2(0);
    if(cntn==n)return n;
}

int res;
void dfs1(int u,int m,int cnt)
{
    if(cnt>n)return ;
    if(u==m)
    {
        if(connected(m)&&cnt==n)
        {
            ++res;
        }
    }
    else
    {
        use[u]=1;
        dfs1(u+1,m,cnt+1);
        use[u]=0;
        dfs1(u+1,m,cnt);
    }
}
int main()
{

    while(cin>>n)
    {
        int m = n*(n-1)/2;
        memset(use,false,sizeof(use));
        res=0;
        dfs1(0,m,0);
        printf("%d\n",res);
    }
	return 0;
}
