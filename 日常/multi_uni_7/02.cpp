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

struct Point
{
    double x,y;
    double r;
    Point() {}
    Point(double _x,double _y):x(_x),y(_y) {}
    Point(Point a,Point b)
    {
        x = b.x-a.x;
        y = b.y-a.y;
    }
    Point Rotate(double theta)
    {
        return Point(x * cos(theta)- y * sin(theta), x * sin(theta) +
                     y * cos(theta));
    }
    Point operator-(Point a)
    {
        return Point(x-a.x, y-a.y);
    }
    Point Rotate(Point center, double theta)
    {
        Point tmp = *this - center;
        return tmp.Rotate(theta) + center;
    }
    Point operator+(Point a)
    {
        return Point(x + a.x, y + a.y);
    }
};

void calc_qie(Point poi,Point o,double r,Point &result1,Point &result2)
{
    double line = sqrt((poi.x-o.x)*(poi.x-o.x)+(poi.y-o.y)*(poi.y-o.y));
    double angle = acos(r/line);
    Point unitvector,lin;
    lin.x = poi.x-o.x;
    lin.y = poi.y-o.y;
    unitvector.x = lin.x/sqrt(lin.x*lin.x+lin.y*lin.y)*r;
    unitvector.y = lin.y/sqrt(lin.x*lin.x+lin.y*lin.y)*r;
    result1 = unitvector.Rotate(-angle);
    result2 = unitvector.Rotate(angle);
    result1.x += o.x;
    result1.y += o.y;
    result2.x += o.x;
    result2.y += o.y;
}
int tn,tc;
Point tp[555];
void Gao()
{
    Point c[55];
    tn = 0;
    Point a,b,vab;
    double tab,tt,dis,theta;
    for (int i = 0; i < tc; i++)
        for (int j = 0; j < tc; j++)
            if (i != j)
            {
                a = c[i];
                b = c[j];
                vab = Point(a,b);
                tab = atan2(vab.y,vab.x);
                dis = sqrt(vab.x*vab.x+vab.y*vab.y);
                if (b.r > a.r)
                    tt = asin((b.r-a.r)/dis);
                else
                    tt = asin((a.r-b.r)/dis);
                theta = tab+PI/2+tt;
                tp[tn++] = Point(a.x+a.r*cos(theta),a.y+a.r*sin(theta));
                tp[tn++] = Point(b.x+b.r*cos(theta),b.y+b.r*sin(theta));
            }
}
int main()
{
    return 0;
}
