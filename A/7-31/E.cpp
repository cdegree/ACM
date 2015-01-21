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

int dx[]= {0, 0,1,1, 1,-1,-1,-1};
int dy[]= {1,-1,0,1,-1, 0, 1,-1};
const int N = 105;
int dis[3][N][N];
int n,m;
char mp[N][N];
bool vis[N][N];
const int inf=1e7;

vector< pair<int,int> > vp[27];

bool isupper(char c)
{
    return c>='A'&&c<='Z';
}

void init()
{
    for(int i=0; i<27; ++i)vp[i].clear();
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(isupper(mp[i][j]))
            {
                vp[ mp[i][j]-'A' ].push_back( make_pair(i,j) );
            }
        }
    }
//    for(int i=0;i<26;++i)
//    {
//        if(vp[i].size()>0)
//        {
//            for(int j=0;j<vp[i].size();++j)
//            {
//                printf("%d %d\n",vp[i][j].X,vp[i][j].Y);
//            }
//        }
//    }
}

bool ok(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m&&mp[x][y]!='#'&&mp[x][y]!='*';
}
void bfs(int id,int x,int y)
{
    queue<int> Q;
    memset(vis,false,sizeof(vis));
    Q.push(x);
    Q.push(y);

    //printf("start %d %d\n",x,y);
    for(int i=0; i<N; ++i)for(int j=0; j<N; ++j)dis[id][i][j]=inf;
    dis[id][x][y]=0;
    while(!Q.empty())
    {
        int ux=Q.front();
        Q.pop();
        int uy=Q.front();
        Q.pop();
        //printf("%d %d\n",ux,uy);
        for(int k=0; k<8; ++k)
        {
            int nx = ux+dx[k];
            int ny = uy+dy[k];
            if(ok(nx,ny)&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                dis[id][nx][ny]=min(dis[id][nx][ny],dis[id][ux][uy]+1);
                Q.push(nx);
                Q.push(ny);
                if(isupper(mp[nx][ny]))
                {
                    int pos = mp[nx][ny] - 'A';
                    int len = vp[ pos ].size();
                    for(int j=0; j<len; ++j )
                    {
                        int vx = vp[pos][j].X;
                        int vy = vp[pos][j].Y;
                        if(!vis[vx][vy])
                        {
                            vis[vx][vy]=true;
                            Q.push(vx);
                            Q.push(vy);
                            dis[id][vx][vy]=min(dis[id][vx][vy],dis[id][ux][uy]+1);
                        }
                    }
                }
            }
        }
    }
}


int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; ++i)
        {
            scanf("%s",mp[i]);
        }
        init();
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(mp[i][j]=='$')
                {
                    bfs(0,i,j);
                }
                else if(mp[i][j]=='!')
                {
                    bfs(1,i,j);
                }
                else if(mp[i][j]=='*')
                {
                    bfs(2,i,j);
                }
            }
        }
//        for(int k=0; k<3; ++k)
//        {
//            printf("%d:\n",k);
//            for(int i=0; i<n; ++i)
//            {
//                for(int j=0; j<m; ++j)
//                {
//                    printf("%d ",dis[k][i][j]);
//                }
//                puts("");
//
//            }
//        }
        int res=inf;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                res=min(res,max(dis[0][i][j],dis[1][i][j])+dis[2][i][j]);
            }
        }
        if(res==inf)
        {
            puts("Impossible");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}
