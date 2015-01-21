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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const double eps = 1e-6;
bool dy(double x, double y)  {   return x > y + eps;} // x > y
bool xy(double x, double y)  {   return x < y - eps;} // x < y
bool dyd(double x, double y) {   return x > y - eps;} // x >= y
bool xyd(double x, double y) {   return x < y + eps;}    // x <= y
bool dd(double x, double y)  {   return fabs(x - y) < eps;}   // x == y

struct point {
    double x, y;
};
point C;

int quad(point a) { // 判断象限的函数，每个象限包括半个坐标轴
    if(dy(a.x, 0) && dyd(a.y, 0)) return 1;
    if(xyd(a.x, 0) && dy(a.y, 0)) return 2;
    if(xy(a.x, 0) && xyd(a.y, 0)) return 3;
    if(dyd(a.x, 0) && xy(a.y, 0)) return 4;
}

double crossProduct(point c, point a, point b) {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

bool cmp2(const point& a, const point& b) {
    point p1 = a, p2 = b;
    p1.x -= C.x; p1.y -= C.y;
    p2.x -= C.x; p2.y -= C.y;
    int l1, l2;
    l1 = quad(p1); l2 = quad(p2);
    if(l1 == l2) {
        double c = crossProduct(C, a, b);
        return dy(c, 0) || dd(c, 0.0) && xy(fabs(a.x), fabs(b.x));
    }
    return l1 < l2;
}
const int N = 1005;
point P[N];
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%lf %lf",&P[i].x,&P[i].y);
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;++i)
        {

        }
    }
    return 0;
}
