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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

int n;
const int N = 1005;

struct point {
    int x, y;
    int d;
};
point P[2];
bool vis[2][N][N];

pair<int, int> res;
bool OK;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

pair< pair<int, int> , int> move(pair< pair<int, int> , int> p,int k) {
    int d = p.Y;
    if(d==-1)return p;
    int ddx = dx[d];
    int ddy = dy[d];
    pair<int, int> cd = p.X;
    cd.X += ddx;
    cd.Y += ddy;
    if(in(cd.X, cd.Y)&&!vis[k][ cd.X ][ cd.Y ]) {
        p.X = cd;
        vis[k][ cd.X ][ cd.Y ]=1;
    }
    else {
        if(k==0)d = (d + 1) % 4;
        else d = (d+3)%4;
        ddx = dx[d];
        ddy = dy[d];
        cd = p.X;
        cd.X += ddx;
        cd.Y += ddy;
        if(in(cd.X, cd.Y)&&!vis[k][ cd.X ][ cd.Y ]) {
            p.Y = d;
            p.X = cd;
            vis[k][ cd.X ][ cd.Y ]=1;
        }
        else {
            p.Y = -1;
        }
    }
    return p;
}

void pf(pair< pair<int,int>,int > p)
{
    printf("%d %d  -> %d\n",p.X.X,p.X.Y,p.Y);
}
void gao() {
    OK = 0;
    pair< pair<int,int>,int > ppd,ppt;
    ppd.X.X = P[0].x;
    ppd.X.Y = P[0].y;
    ppd.Y = P[0].d;
    ppt.X.X = P[1].x;
    ppt.X.Y = P[1].y;
    ppt.Y = P[1].d;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<2;++i)
    {
        vis[i][ P[i].x ][ P[i].y ]=1;
    }
    while(1)
    {
        ppd = move(ppd,0);
        ppt = move(ppt,1);
        //pf(ppd);
        //pf(ppt);
        if(ppd.Y==ppt.Y&&ppd.Y==-1)
        {
            OK=0;
            break;
        }
        if(ppd.X.X==ppt.X.X&&ppd.X.Y==ppt.X.Y)
        {
            OK=1;
            res = make_pair(ppd.X.X,ppd.X.Y);
            break;
        }
    }
}


int main() {

    while(~scanf("%d", &n)) {
        if(n==0)break;
        for(int i = 0; i < 2; ++i) {
            scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].d);
        }
        gao();
        if(OK) {
            printf("%d %d\n", res.first, res.second);
        }
        else {
            puts("-1");
        }

    }
    return 0;
}
