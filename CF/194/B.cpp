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
    int x,y;
} P[8];

bool cmp(point a,point b)
{
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    for(int i=0; i<8; ++i)
    {
        scanf("%d %d",&P[i].x,&P[i].y);
    }
    sort(P,P+8,cmp);
    set<int> sx,sy;
    for(int i=0; i<8; ++i)
    {
        sx.insert(P[i].x);
        sy.insert(P[i].y);
    }
    if(sx.size()!=3||sy.size()!=3)
    {
        puts("ugly");
        return 0;
    }
    int cntx[3]= {0},cnty[3]= {0};
    for(int i=0; i<8; ++i)
    {
        int len=0;
        for(set<int>::iterator it = sx.begin(); it!=sx.end(); ++it)
        {
            if(P[i].x==(*it))
            {
                cntx[len]++;
            }
            len++;
        }
        len=0;
        for(set<int>::iterator it = sy.begin(); it!=sy.end(); ++it)
        {
            if(P[i].y==(*it))
            {
                cnty[len]++;
            }
            len++;
        }

    }
    for(int i=0;i<3;++i)
    {
        //printf("%d %d\n",cntx[i],cnty[i]);
    }
    if(cntx[1]!=2||cnty[1]!=2||cntx[0]!=3
            ||cntx[2]!=3||cnty[0]!=3||cnty[2]!=3)
    {
        puts("ugly");
    }
    else
    {
        puts("respectable");
    }
    return 0;
}
