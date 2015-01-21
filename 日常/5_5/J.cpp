#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;


typedef long long LL ;

int n,m;
char s[205][205];

int dx[]={1,1,0,-1};
int dy[]={1,0,1,1};
bool in(int x,int y)
{
    return x>=0&&y>=0&&x<n&&y<m;
}
bool faut;
bool can_here_win(int x,int y,char c)
{
    for(int k=0;k<4;++k)
    {
        int Lx = x;
        int Ly = y;
        int Rx = x;
        int Ry = y;
        while(in(Lx-dx[k],Ly-dy[k])&& s[ Lx-dx[k] ][ Ly-dy[k] ]==c)
        {
            Lx -= dx[k];
            Ly -= dy[k];
        }
        while(in(Rx+dx[k],Ry+dy[k])&& s[ Rx+dx[k] ][ Ry+dy[k] ]==c)
        {
            Rx += dx[k];
            Ry += dy[k];
        }
        //printf("%d,%d -> %d,%d\n",Lx,Ly,Rx,Ry);
        int ab1 = abs(Lx-Rx)+1;
        int ab2 = abs(Ly-Ry)+1;
        int dis = max( ab1, ab2 );
        if(dis>=5)return true;
        //if(dis>9)faut=true;
    }
    return false;
}

bool Can_Win(char c)
{
    bool OK=false;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(s[i][j]==c&&can_here_win(i,j,c))
            {
                OK = true;
            }
        }
    }
    return OK;
}

int count(char c)
{
    int ret = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            ret += ((s[i][j]==c)?1:0);
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&n,&m))
	{
	    for(int i=0;i<n;++i)
	    {
	        scanf("%s",s[i]);
	    }
	    faut=false;
	    bool win1 = Can_Win('1');
	    bool win2 = Can_Win('2');
	    //printf("%d %d %d\n",win1,win2,faut);
	    int cnt1 = count('1');
	    int cnt2 = count('2');
	    if(abs(cnt1-cnt2)>1)faut=true;
	    if(win1&&win2)
	    {
	        puts("fault");
	    }
	    else if(win1&&!faut)
	    {
	        puts("white");
	    }
	    else if(win2&&!faut)
	    {
	        puts("black");
	    }
	    else if(faut)
	    {
	        puts("fault");
	    }
	    else
	    {
	        puts("other");
	    }
	}
	return 0;
}
