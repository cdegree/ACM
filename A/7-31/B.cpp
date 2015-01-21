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

int n;
struct point
{
    int x,y;
}P[105];

double get_dis(point a,point b)
{
    return sqrt((double)sqr(a.x-b.x)+(double)sqr(a.y-b.y));
}
bool op[2002][2002];
int main()
{
    while(cin>>n)
    {
        memset(op,false,sizeof(op));
        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&P[i].x,&P[i].y);
            op[P[i].x+1000][P[i].y+1000]=true;
        }
        double most=0;
        int xi=0,xj=0;
        while(op[xi][xj])++xi;
        P[n].x=xi;
        P[n].y=xj;
        for(int i=0;i<n;++i)
        {
            if(most<get_dis(P[i],P[n]))
            {
                most=get_dis(P[i],P[n]);
            }
        }
        double r = most;
        printf("%d %d %.9f\n",P[n].x,P[n].y,r);
    }
	return 0;
}
