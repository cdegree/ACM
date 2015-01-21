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

char s[105][105];
int cnt1,cnt0;
int w,h;
int dx[]={0,0,-1,1,-1,1,-1,1};
int dy[]={-1,1,0,0,-1,-1,1,1};
bool vis[105][105];
bool in(int x,int y)
{
	printf("%d;%d; %d====%d\n",h,w,x,y);
	return x>=0&&x<h&&y>=0&&y<w;
}
bool wall(int x,int y)
{
	if(s[x][y]=='\\'||s[x][y]=='/')
	{
		return true;
	}
	return false;
}
bool check(int x,int y)
{
	printf("%d,%d\n",x,y);
	if(wall(x,y))
	{
		return true;
	}
	bool OK=true;
	
	for(int k=0;k<4;++k)
	{
		int ddx = dx[k];
		int ddy = dy[k];
		int xx=x,yy=y;
		while(in(xx,yy)&&!wall(xx,yy))
		{
			xx += ddx;
			yy += ddy;
		}
		if(!in(xx,yy))
		{
			OK=false;
			break;
		}
	}
	return OK;
}
void gao(int x,int y)
{
	if(wall(x,y))
	{
		++cnt0;
	}
	else 
	{
		++cnt1;
	}
	printf("%d,,%d = %c\n",x,y,s[x][y]);
	vis[x][y]=1;
	for(int k=0;k<8;++k)
	{
		int ddx = dx[k];
		int ddy = dy[k];
		//printf("%d,,,%d = %c\n",ddx+x,ddy+y,s[ddx+x][ddy+y]);

		if(in(ddx+x,ddy+y)&& !vis[ddx+x][ddy+y]&&  check(ddx+x,ddy+y))
		{
			//puts("IN");
			gao(ddx+x,ddy+y);
		}
	}
}
void ggao()
{
	memset(vis,false,sizeof(vis));
	for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				if(s[i][j]=='\\'||s[i][j]=='/')
				{
					gao(i,j);
					return ;
				}
			}
		}
}
int main(int argc, char const *argv[])
{
	freopen("Ain.txt","r",stdin);
	
	while(~scanf("%d%d",&h,&w))
	{
		for(int i=0;i<h;++i)
		{
			scanf("%s",s[i]);
		}
		cnt0=cnt1=0;
		ggao();
		printf("%d %d\n",cnt0,cnt1);
	}
	return 0;
}