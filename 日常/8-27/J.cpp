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

int k;
struct point
{
    int x,y,r;
} P[12];

bool test_bit(int mask,int pos)
{
    return ((1<<pos)&mask)!=0;
}
int mp[55][55];
int n;
void cover(point p)
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(mp[i][j])continue;
            if(abs(i-p.x)+abs(j-p.y)<=p.r)
            {
                mp[i][j]=1;
            }
        }
    }
}
bool all()
{
    bool ok=1;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            //printf("%d ",mp[i][j]);
            if(!mp[i][j])ok=0;
        }
        //puts("");
    }//puts("");
    return ok;
}
int main()
{

    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&k);
        for(int i=0; i<k; ++i)
        {
            scanf("%d%d",&P[i].x,&P[i].y);
        }
        for(int i=0; i<k; ++i)
        {
            scanf("%d",&P[i].r);
        }
        int res=12;
        for(int mask=0; mask<(1<<k); ++mask)
        {
            memset(mp,0,sizeof(mp));
            int cnt=0;
            for(int i=0; i<k; ++i)
            {
                mp[ P[i].x ][ P[i].y ]=1;
                if(test_bit(mask,i))
                {
                    ++cnt;
                    cover(P[i]);
                }
            }
            if(all())
            {
                res=min(res,cnt);
            }
        }
        printf("%d\n",res==12?-1:res);
    }
    return 0;
}
