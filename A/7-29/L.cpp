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
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

LL n,m,k;
struct point
{
    int x,y;
};
const int N = 100005;
point P[N];
bool cmp(point a,point b)
{
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}
int Y[N];
int X[N];
bool JJJ(int pos1,int pos2)
{
    return abs(pos1-pos2)%2==1;
}
bool judge1(int from,int to,int *ff)
{
    if(to-from==1)
    {
        return true;
    }
    bool pre=false;
    if(ff[from]>1)
    {
        pre=true;
    }
    for(int i=from;i<to-1;++i)
    {
        if(abs(ff[i],))
    }
}
bool judge2(int from,int to,int *ff)
{
    if(to-from==1)
    {
        return true;
    }
    for(int i=from;i<to-1;++i)
    {
        if(abs(ff[i]-ff[i+1])==1&&ff[i]>1&&ff[i+2]<m&&ff[i+2]==ff[i+1]+1)
        {
            return false;
        }
        if(abs(ff[i]-ff[i+1])%2==0)
        {
            return false;
        }
    }
    return true;
}
set<pair<int,int> > sp;
int main()
{
    while(~scanf("%I64d%I64d%I64d",&n,&m,&k))
    {
        int x,y;
        sp.clear();
        for(int i=0;i<k;++i)
        {
            scanf("%d %d",&P[i].x,&P[i].y);
            sp.insert(make_pair(P[i].x,P[i].y));
        }
        LL leny=0;
        sort(P,P+k,cmp);
        //set< pair<int,int> >::iterator it = sp.begin();
        y=P[0].y;
        Y[leny++]=y;
        for(int i=0;i<k;++i)
        {
            if( P[i].y !=y)
            {
                Y[leny++]=P[i].y;
                //printf("%d\n",P[i].y);
                //SY.insert(P[i].y);
            }
            y=P[i].y;
        }
        int p=0;
        LL lenx=0;
        int prex=-1;
        for(int i=0;i<k;++i)
        {
            if(P[i].y==Y[0]&&prex!=P[i].x)
            {
                prex=P[i].x;
                X[lenx++]=P[i].x;
                //SX.insert(P[i].x);
            }
            else
            {
                break;
            }
        }
//        printf("%lld,%lld  =%d\n",lenx,leny,sp.size());
//        for(int i=0;i<lenx;++i)
//        {
//            printf("%d ",X[i]);
//        }
//        puts("");
//        for(int i=0;i<leny;++i)
//        {
//            printf("%d ",Y[i]);
//        }
//        puts("");
        if(lenx*leny!=sp.size())
        {
            puts("NO");
            //puts("ok");
        }
        else
        {
            bool ok1=false;
            bool ok2=false;
            bool ok=false;
            ok1=judge1(0,lenx,X);
            ok2=judge2(0,leny,Y);
            if(ok1&&ok2)ok=true;
            if(ok)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
	return 0;
}
