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

using namespace std;

typedef long long LL ;
struct point
{
    LL x,y;
    point(){}
    point(LL _x,LL _y)
    {
        x=_x;
        y=_y;
    }
};
struct segment
{
    point st,ed;
    LL A,B,C;
    segment(){}
    segment(point _st,point _ed)
    {
        st=_st;
        ed=_ed;
        A = st.y - ed.y;
        B = ed.x - st.x;
        C = (st.y-ed.y)*st.x - (st.x-ed.x)*st.y;
    }
    point intersect(segment s)
    {
        LL A1 = A, B1 = B, C1 = C;
        LL A2 = s.A, B2 = s.B, C2 = s.C;

        A1 *=s.A, B1 *= s.A, C1 *= s.A;
        A1 *=A, B1 *= A, C1 *= A;
        if(B1-B2==0)
        {

        }
        else
        {

        }
    }
};
vector<point> vp;
vector<segment> vs;
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        LL x1,y1,x2,y2;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld %lld%lld",&x1,&y1,&x2,&y2);
            vs.push_back(segment(point(x1,y1),point(x2,y2)));
        }
    }
	return 0;
}
