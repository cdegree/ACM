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

char s[200][200];
int n,m;
bool in(int x,int y)
{
    return x<=n&&y>=0&&y<m;
}
bool vis[222][222];
int gao(int x,int y)
{
    memset(vis,false,sizeof(vis));
    //puts("ok");
    bool ok=1;
    while(1)
    {
        //printf("%d %d\n",x,y);
        if(x==n)break;
        if(s[x][y]=='/'&&!vis[x][y])
        {
            vis[x][y]=1;
            --y;
            if(!in(x,y)){ok=0;break;}
            if(s[x][y]=='/')++x;
        }
        else if(s[x][y]=='\\'&&!vis[x][y])
        {
            vis[x][y]=1;
            ++y;
            if(!in(x,y)){ok=0;break;}
            if(s[x][y]=='\\')++x;
        }
        else if(!vis[x][y])
        {
            ++x;
        }
        else
        {
            ok=0;break;
        }
    }
    if(!ok)return -1;
    return y+1;
}
int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i)scanf("%s",s[i]);
        int res=-1;
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(s[i][j]=='P')res=gao(i,j);
        printf("%d\n",res);
    }
	return 0;
}
