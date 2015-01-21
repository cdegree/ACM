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

struct point {
    double x, y;
};
point P[1005];


double get_dis(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

point intersection(point u1, point u2, point v1, point v2) {
    point ret = u1;
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x))
               / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}
point ptoline(point p, point l1, point l2) {
    point t = p;
    t.x += l1.y - l2.y, t.y += l2.x - l1.x;
    return intersection(p, t, l1, l2);
}

int n;
double get_D(point st, point ed) {
    double ret = 0;
    for(int i = 0; i < n; ++i) {
        point t = ptoline(P[i], st, ed);
        ret += get_dis(t, P[i]);
    }
    return ret;
}
const int K = 1000;
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        double res = 1e300;
        for(int i = 0; i < K; ++i) {
            double x = cos(PI * i / K);
            double y = sin(PI * i / K);
            point st, ed;
            st.x = -1e7 * y;
            st.y = -1e7 * x;
            ed.x = 1e7 * x;
            ed.y = 1e7 * y;

            double l = -1e7 , r = 1e7, mid1, mid2, ans;
            for(int j = 0; j < 300; ++j) {
                mid1 = l + (r - l) / 3;
                mid2 = l + (r - l) * 2 / 3;
                point st1, ed1, st2, ed2;
                st1 = st2 = st, ed1 = ed2 = ed;
                st1.y += mid1;
                ed1.y += mid1;
                st2.y += mid2;
                ed2.y += mid2;
                if(get_D(st1, ed1) < get_D(st2, ed2)) {
                    r = mid2;
                }
                else {
                    l = mid1;
                }
            }
            st.y += mid2;
            ed.y += mid2;
            checkmin(res, get_D(st, ed));
        }
        printf("%.6f\n", res);
    }
    return 0;
}
