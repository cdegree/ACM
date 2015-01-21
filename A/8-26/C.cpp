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
    point() {}
    point(int _x,int _y):x(_x),y(_y) {}
} P[3];
int n;

struct building
{
    point a,b,c,d;
    bool exist;
} B[3055];

int hash[822];
int m;
set<int> st;
int get_hash(int x)
{
    int pos=1;
    for(set<int>::iterator it=st.begin(); it!=st.end(); ++it,pos=pos+2)
    {
        if( (*(it))==x)
        {
            break;
        }
    }
    return pos;
}
int vis[522][522];
int dis[522][522];
int wall[522][522];

void cover(int id)
{
    int lx = min(B[id].a.x,B[id].b.x);
    int ux = max(B[id].a.x,B[id].b.x);
    int ly = min(B[id].a.y,B[id].b.y);
    int uy = max(B[id].a.y,B[id].b.y);
    if(ly+1<=uy-1)
        for(int i=lx+1; i<ux; ++i)
        {
            wall[i][ly+1]=wall[i][uy-1]=1;
        }
    if(lx+1<=ux-1)
        for(int i=ly+1; i<uy; ++i)
        {
            wall[lx+1][i]=wall[ux-1][i]=1;
        }
}

void gao(int id)
{
    int lx = min(B[id].a.ox,B[id].b.ox);
    int ux = max(B[id].a.ox,B[id].b.ox);
    int ly = min(B[id].a.oy,B[id].b.oy);
    int uy = max(B[id].a.oy,B[id].b.oy);
    st.insert(lx);
    st.insert(ly);
    st.insert(ux);
    st.insert(uy);
    B[id].exist=1;
    B[id].a.x=lx;
    B[id].a.y=ly;
    B[id].b.x=ux;
    B[id].b.y=uy;
}

int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
bool in(int x,int y)
{
    return x>=0&&x<m&&y>=0&&y<m;
}

int len;
struct segment
{
    point a,b;
    segment() {}
    segment(point _a,point _b):a(_a),b(_b) {}
};

vector<segment> intosegmtn(int id)
{
    int lx = min(B[id].a.x,B[id].b.x);
    int ux = max(B[id].a.x,B[id].b.x);
    int ly = min(B[id].a.y,B[id].b.y);
    int uy = max(B[id].a.y,B[id].b.y);
    vector<segment> vs;
    vs.push_back(segment(point(lx,ly),point(lx,uy)));
    vs.push_back(segment(point(lx,ly),point(ux,ly)));
    vs.push_back(segment(point(lx,uy),point(ux,uy)));
    vs.push_back(segment(point(ux,ly),point(ux,uy)));
    return vs;
}



bool get_cross(int id1,int id2,building &tmp)
{
    vector<segment> vs1 = intosegmtn(id1);
    vector<segment> vs2 = intosegmtn(id2);
    building ret;
    point a,b;
    int inf=2e8;
    a.x=a.y=inf;
    b.x=b.y=-inf;
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            if(vs1[i].a.x==vs1[i].b.x&&vs1[i].a.x==vs2[j].a.x&&vs1[i].a.x==vs2[j].b.x)
            {
                int vs1ly = min(vs1[i].a.y,vs1[i].b.y);
                int vs1uy = max(vs1[i].a.y,vs1[i].b.y);
                int vs2ly = min(vs2[i].a.y,vs2[i].b.y);
                int vs2uy = max(vs2[i].a.y,vs2[i].b.y);
                if(max(vs1ly,vs2ly)<=min(vs1uy,vs2uy))
                {
                    b.x=a.x=vs1[i].a.x;
                    a.y=max(vs1ly,vs2ly);
                    b.y=min(vs1uy,vs2uy);
                }
            }
            else if(vs1[i].a.y==vs1[i].b.y&&vs1[i].a.y==vs2[j].a.y&&vs1[i].a.y==vs2[j].b.y)
            {
                int vs1lx = min(vs1[i].a.x,vs1[i].b.x);
                int vs1ux = max(vs1[i].a.x,vs1[i].b.x);
                int vs2lx = min(vs2[i].a.x,vs2[i].b.x);
                int vs2ux = max(vs2[i].a.x,vs2[i].b.x);
                if(max(vs1lx,vs2lx)<=min(vs1ux,vs2ux))
                {
                    b.y=a.y=vs1[i].a.y;
                    a.x=max(vs1lx,vs2lx);
                    b.x=min(vs1ux,vs2ux);
                }
            }
        }
    }
    bool ok;
    if(a.x==inf)
    {
        ok=0;
    }
    else
    {
        --a.x;
        --a.y;
        ++b.x;
        ++b.y;
        ok=1;
    }
    //printf("%d cross %d:  to %d,%d ----->  %d,%d\n",id1,id2,a.ox,a.oy,b.ox,b.oy);
    ret.a=a;
    ret.b=b;
    tmp = ret;
    return ok;
}

int main()
{
    while(1)
    {
        len=0;
        st.clear();
        for(int i=0; i<2; ++i)
        {
            scanf("%d%d",&P[i].ox,&P[i].oy);
            st.insert(P[i].ox);
            st.insert(P[i].oy);
        }
        if(P[0].ox==0&&P[0].oy==0&&P[1].ox==0&&P[1].oy==0)break;
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d%d%d",&B[i].a.ox,&B[i].a.oy,&B[i].b.ox,&B[i].b.oy);
        }
        for(int i=0; i<n; ++i)
        {
            gao(i);
        }
        int pos=1;
        for(set<int>::iterator it=st.begin(); it!=st.end(); ++it,pos=pos+2)
        {
            printf("%d --> %d\n",pos,*it);
        }
        m = pos+1;
        //printf("size = %d\n",m);
        for(int i=0; i<2; ++i)
        {
            P[i].x=get_hash(P[i].ox);
            P[i].y=get_hash(P[i].oy);
            //printf("%d,%d\n",P[i].x,P[i].y);
        }
        for(int i=0; i<n; ++i)
        {
            //if(!B[i].exist)continue;
            B[i].a.x=get_hash(B[i].a.ox);
            B[i].a.y=get_hash(B[i].a.oy);
            B[i].b.x=get_hash(B[i].b.ox);
            B[i].b.y=get_hash(B[i].b.oy);
        }
        //for(int i=0; i<n; ++i)printf("%d,%d  ->  %d,%d\n",B[i].a.x,B[i].a.y,B[i].b.x,B[i].b.y);

        queue<int> Q;
        const int inf = 333;
        for(int i=0; i<522; ++i)for(int j=0; j<522; ++j)dis[i][j]=inf;
        memset(vis,false,sizeof(vis));
        memset(wall,false,sizeof(wall));
        for(int i=0; i<n; ++i)
        {
            cover(i);
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                building tmp;
                if(get_cross(i,j,tmp))
                {
                    B[n]=tmp;
                    cover(n);
                }
            }
        }
        //puts("here");
        Q.push(P[0].x);
        Q.push(P[0].y);
        dis[ P[0].x ][ P[0].y ]=-1;
        vis[ P[0].x ][ P[0].y ]=1;
        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            vis[x][y]=2;
            //printf("as  %d,%d  kuochong le xielie jidian \n",x,y);
            for(int k=0; k<4; ++k)
            {
                int ddx = dx[k];
                int ddy = dy[k];
                int nx = ddx+x;
                int ny = ddy+y;
                while(in(nx,ny)&&!wall[nx][ny]&&vis[nx][ny]!=2)
                {
                    if(dis[x][y]+1<dis[nx][ny])
                    {
                        dis[nx][ny]=dis[x][y]+1;
                        if(vis[nx][ny]==0)
                        {
                            vis[nx][ny]=1;
                            Q.push(nx);
                            Q.push(ny);
                        }
                    }
                    nx = ddx+nx;
                    ny = ddy+ny;
                }
            }
        }
        for(int i=0; i<m; ++i){for(int j=0; j<m; ++j)printf("%4d",dis[i][j]);puts("");}
        printf("dest = %d %d\n",P[1].x,P[1].y);
        if(dis[ P[1].x ][ P[1].y ]==inf)
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
