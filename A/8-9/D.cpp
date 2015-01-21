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
const int N = 55;

bool valid[N][N][4];

int r,c,n;

int dis[N][N];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

void gao(int sx,int sy,int ox,int oy)
{
    if(sx==ox&&sx>0&&sx<r)
    {
        for(int i=sy;i<oy;++i)
        {
            valid[sx][i-1][0]=false;
            valid[sx][i][2]=false;
        }
    }
    else
    {
        for(int i=sx;i<ox;++i)
        {
            valid[i-1][sy][1]=
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&r,&c,&n))
    {
        int sx,sy,ox,oy;
        memset(valid,false,sizeof(valid));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d%d",&sx,&sy,&ox,&oy);
        }

    }
	return 0;
}
