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
    double x,y;
};

double get_dis(point a,point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

double get_cosA(double a,double b,double c)
{
    return sqr(b)+sqr(c)-sqr(a)/2/b/c;
}
point rp1,rp2;
const double eps=1e-9;
bool gao(point p1,point p2,point p3)
{
    double a = get_dis(p1,p2);
    double b = get_dis(p1,p3);
    double c = get_dis(p2,p3);
    if(a>b)
    {
        swap(a,b);
        swap(p2,p3);
    }
    double sum = (a+b+c)/2;
    if(sqr(sum)<2*a*b)
    {
        return false;
    }
    else
    {
        double det = sqrt( sqr(sum)-2*a*b );
        double x = (sum - det)/2;
        double y = sum - x;
        if(x>y)swap(x,y);
        if(x>=0&&y>=0)
        {
            if(x<=a&&y<=b)
            {
                rp1.x=p1.x + (p2.x-p1.x)/a*x;
                rp1.y=p1.y + (p2.y-p1.y)/a*x;
                rp2.x=p1.x + (p3.x-p1.x)/b*y;
                rp2.y=p1.y + (p3.y-p1.y)/b*y;
            }
            else
            {
                return false;
            }
        }
        else
        {
            x = (sum + det)/2;
            y = sum - x;
            if(x<=a&&y<=b)
            {
                rp1.x=p1.x + (p2.x-p1.x)/a*x;
                rp1.y=p1.y + (p2.y-p1.y)/a*x;
                rp2.x=p1.x + (p3.x-p1.x)/b*y;
                rp2.y=p1.y + (p3.y-p1.y)/b*y;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    point P[3];
    //printf("%.9f\n",sin(1.7));
    while(~scanf("%lf%lf",&P[0].x,&P[0].y))
    {
        for(int i=1; i<3; ++i)scanf("%lf%lf",&P[i].x,&P[i].y);
        if(gao(P[0],P[1],P[2])||gao(P[1],P[2],P[0])
           ||gao(P[2],P[0],P[1]))
           {
               puts("YES");
               printf("%.9f %.9f\n",rp1.x,rp1.y);
               printf("%.9f %.9f\n",rp2.x,rp2.y);
           }
           else
           {
               puts("NO");
           }
    }
    return 0;
}

