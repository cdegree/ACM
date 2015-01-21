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

struct point
{
    int ox,oy;
    int x,y;
} P[55];
int n;

struct building
{
    point a,b;
}B[55];

int hash[222];
int m;
set<int> st;
int get_hash(int x)
{
    int pos=1;
    for(set<int>::iterator it=st.begin();it!=st.end();++it,++pos)
    {
        if(*(it)==x)
        {
            break;
        }
    }
    return pos;
}
int vis[222][222];
int dis[222][222];

void cover(int id)
{
    int lx = min(B[id].a.x,B[id].b.x);
    int ux = max(B[id].a.x,B[id].b.x);
    int ly = min(B[id].a.y,B[id].b.y);
    int uy = max(B[id].a.y,B[id].b.y);
    for(int i=lx;i<=ux;++i)
    {
        vis[i][ly]=vis[i][uy]=1;
    }
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool in(int x,int y)
{
    return x>=0&&x<m&&y>=0&&y<m;
}
int main()
{
    while(1)
    {
        int len=0;
        st.clear();
        for(int i=0; i<2; ++i)
        {
            scanf("%d%d",&P[i].ox,&P[i].oy);
            st.insert(P[i].ox);
            st.insert(P[i].oy);
        }
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d%d%d",&B[i].a.ox,&B[i].a.oy,&B[i].b.ox,&B[i].b.oy);
            st.insert(B[i].a.ox);
            st.insert(B[i].a.oy);
            st.insert(B[i].b.ox);
            st.insert(B[i].b.oy);
        }
        m = st.size()+3;
        //printf("size = %d\n",st.size());
        for(int i=0;i<2;++i)
        {
            P[i].x=get_hash(P[i].ox);
            P[i].y=get_hash(P[i].oy);
            printf("%d,%d\n",P[i].x,P[i].y);
        }
        for(int i=0;i<n;++i)
        {
            B[i].a.x=get_hash(B[i].a.ox);
            B[i].a.y=get_hash(B[i].a.oy);
            B[i].b.x=get_hash(B[i].b.ox);
            B[i].b.x=get_hash(B[i].b.oy);
        }
        for(int i=0;i<n;++i)
        {
            printf("%d,%d  ->  %d,%d\n",B[i].a.x,B[i].a.y,B[i].b.x,B[i].b.y);
        }
        queue<int> Q;
        for(int i=0;i<222;++i)for(int j=0;j<222;++j)dis[i][j]=3333;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;++i)
        {
            cover(i);
        }
        Q.push(P[0].x);
        Q.push(P[0].y);
        dis[ P[0].x ][ P[0].y ]=0;
        vis[ P[0].x ][ P[0].y ]=1;
        while(!Q.empty())
        {
            int x = Q.front();Q.pop();
            int y = Q.front();Q.pop();
            for(int k=0;k<4;++k)
            {
                int ddx = dx[k];
                int ddy = dy[k];
                int nx = ddx+x;
                int ny = ddy+y;
                while(in(nx,ny)&&!vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    dis[nx][ny]=dis[x][y]+1;
                    Q.push(nx);
                    Q.push(ny);
                    nx = ddx+nx;
                    ny = ddy+ny;
                }
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<m;++j)
            {
                printf("%6d ",dis[i][j]);
            }
            puts("");
        }
        if(dis[ P[1].x ][ P[1].y ]==3333)
        {
            puts("-1");
        }
        else
        {
            printf("%d\n",dis[ P[1].x ][ P[1].y ]);
        }
    }
    return 0;
}
