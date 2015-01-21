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
const int N = 105;
int fx[N][N][5],fy[N][N][5];
int ins[N*40];
int q;
pair<int,int> gao(int _x,int _y)
{
    int x=_x,y=_y,prex,prey;
    for(int i=0;i<q;++i)
    {
        prex=x;
        prey=y;
        x=fx[prex][prey][ins[i]];
        y=fy[prex][prey][ins[i]];
        //printf("%d,%d\n",x,y);
    }
    pair<int,int> ret = make_pair(x,y);
    return ret;
}
bool OK[N][N];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        set<pair<int,int> > sp;
        for(int k=0;k<4;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    scanf("%d %d",&fx[i][j][k],&fy[i][j][k]);
                }
            }
        }
        scanf("%d",&q);
        for(int i=0;i<q;++i)
        {
            scanf("%d",ins+i);
            --ins[i];
        }
        memset(OK,false,sizeof(OK));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                pair<int,int> now = gao(i,j);
                OK[ now.first ][ now.second ]=true;
            }
        }
        int len=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(OK[i][j])len++;
            }
        }
        printf("%d\n",len);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(OK[i][j])printf("%d %d\n",i,j);
            }
        }
    }
	return 0;
}
