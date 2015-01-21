/********************Cdegree********************/
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
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point {
    double x, y;
};
struct line {
    point a, b;
};


//叉积
double multi(point p0, point p1, point p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}


//相交返回true,否则为false, 接口为两线段的端点
bool isIntersected(point s1, point e1, point s2, point e2) {
    return (max(s1.x, e1.x) >= min(s2.x, e2.x))  &&
           (max(s2.x, e2.x) >= min(s1.x, e1.x))  &&
           (max(s1.y, e1.y) >= min(s2.y, e2.y))  &&
           (max(s2.y, e2.y) >= min(s1.y, e1.y))  &&
           (multi(s1, s2, e1) * multi(s1, e1, e2) >= 0) &&
           (multi(s2, s1, e2) * multi(s2, e2, e1) >= 0);
}


//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1, point p2, point p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double xmult(double x1, double y1, double x2, double y2, double x0, double y0) {
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

//计算dot product (P1-P0).(P2-P0)
double dmult(point p1, point p2, point p0) {
    return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}
double dmult(double x1, double y1, double x2, double y2, double x0, double y0) {
    return (x1 - x0) * (x2 - x0) + (y1 - y0) * (y2 - y0);
}

//两点距离
double get_dis(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double get_dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int offset = 2000;
int inside_polygon(point q, int n, point* p, int on_edge = 2) {
    point q2;
    int i = 0, count;
    while(i < n)
        for(count = i = 0, q2.x = rand() - offset, q2.y = rand() + offset; i < n; i++) {
            if(zero(xmult(q, p[i], p[(i+1)%n])) && (p[i].x - q.x)*(p[(i+1)%n].x - q.x) < eps
                    && (p[i].y - q.y)*(p[(i+1)%n].y - q.y) < eps)
                return on_edge;

            else if(zero(xmult(q, q2, p[i])))
                break;

            else if(xmult(q, p[i], q2)*xmult(q, p[(i+1)%n], q2) < -eps &&
                    xmult(p[i], q, p[(i+1)%n])*xmult(p[i], q2, p[(i+1)%n]) < -eps)
                count++;
        }
    return count & 1;
}


point P[202];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        double res = 0;
        point p;
        p.x=1.01,p.y=.999;
        printf("%d\n",inside_polygon(p, n, P));

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                bool cross = 0;
                point mid;
                mid.x = (P[i].x + P[j].x) / 2;
                mid.y = (P[i].y + P[j].y) / 2;
                if(inside_polygon(mid, n, P) != 1)continue;
                for(int k = 0; k < n; ++k) {
                    if(i != k && i != (k + 1) % n && j != k && j != (k + 1) % n && isIntersected(P[i], P[j], P[k], P[(k+1)%n])) {
                        cross = 1;
                    }
                }
                if(!cross) {
                    checkmax(res, get_dis(P[i], P[j]));
                }
            }
        }
        printf("%.6f\n", res);
    }
    return 0;
}
