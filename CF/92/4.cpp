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
const int N =1003;
int dis[N][N];
bool vis[N][N];
char s[N][N];
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
int r,c;
bool In(int x,int y)
{
    return x>=0&&y>=0&&x<r&&y<c;
}
const int inf=1e7;
int main()
{

    while(cin>>r>>c)
    {
        for(int i=0; i<r; ++i)
        {
            scanf("%s",s[i]);
        }
        int x,y;
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(s[i][j]=='E')
                {
                    x=i;
                    y=j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                dis[i][j]=inf;
            }
        }
        queue<int> Q;
        while(!Q.empty())Q.pop();
        Q.push(x);
        Q.push(y);
        dis[x][y]=0;
        vis[x][y]=true;
        while(!Q.empty())
        {
            int ux=Q.front();
            Q.pop();
            int uy=Q.front();
            Q.pop();
            if(s[ux][uy]=='S')
            {
                break;
            }
            for(int k=0; k<4; ++k)
            {
                int ddx=ux+dx[k];
                int ddy=uy+dy[k];
                if(In(ddx,ddy)&&!vis[ddx][ddy]&&s[ddx][ddy]!='T')
                {
                    vis[ddx][ddy]=true;
                    dis[ddx][ddy]=min(dis[ddx][ddy],dis[ux][uy]+1);
                    Q.push(ddx);
                    Q.push(ddy);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(s[i][j]=='S')
                {
                    cnt = dis[i][j];
                }
            }
        }
        int ans=0;
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(dis[i][j]<=cnt&&s[i][j]!='T'&&s[i][j]!='E'&&s[i][j]!='S')
                {
                    ans += (s[i][j]-'0');
                }
                //printf("%3d",dis[i][j]);
            }
            //puts("");
        }

        printf("%d\n",ans);
    }
    return 0;
}
