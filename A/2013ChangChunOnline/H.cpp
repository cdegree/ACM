#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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

const int N = 1005;
struct point {
    double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
} P[N];
double x, y, d;
int n;
point r;
double get_dis(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
const double eps = 1e-5;
bool Check(point q) {
    for(int i = 0; i < n; ++i) {
        if(get_dis(P[i], q) > d + eps)
            return false;
    }
    return true;
}
bool Check1() {
    point np = r;
    return Check(np);
}

bool Check2(double &res) {
    res = 2e9;
    bool OK = false;
    for(int i = 0; i < n; ++i) {
        double dx = r.x - P[i].x;
        double dy = r.y - P[i].y;
        double dis = get_dis(r, P[i]);
        double nx = (r.x - P[i].x) * d / dis + P[i].x;
        double ny = (r.y - P[i].y) * d / dis + P[i].y;
        point np(nx, ny);
        double ndis = get_dis(np, r);
        if(res > ndis && Check(np)) {
            OK = true;
            res = ndis;
        }
    }
    return OK;
}

bool Check3(double& res) {
    res = 2e9;
    bool OK = false;
    double a, c, b, dx, dy, dis, t, nx, ny, dt, ndx, ndy, ndis;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            point mid ;
            mid.x = (P[i].x + P[j].x) / 2;
            mid.y = (P[i].y + P[j].y) / 2;

            a = get_dis(P[i], mid);
            c = min(d, get_dis(P[i], r));
            dt = c * c - a * a;
            if(dt < -eps)continue;
            b = sqrt(dt);
            dx = P[i].x - P[j].x;
            dy = P[i].y - P[j].y;
            ndx = -dy;
            ndy = dx;

            nx = mid.x + ndx * b / sqrt(sqr(ndx) + sqr(ndy));
            ny = mid.y + ndy * b / sqrt(sqr(ndx) + sqr(ndy));
            point np(nx, ny);
            ndis = get_dis(np, r);
            if(res > ndis && Check(np)) {
                OK = true;
                res = ndis;
            }

            ndx = dy;
            ndy = -dx;

            nx = mid.x + ndx * b / sqrt(sqr(ndx) + sqr(ndy));
            ny = mid.y + ndy * b / sqrt(sqr(ndx) + sqr(ndy));
            np.x = nx;
            np.y = ny;
            ndis = get_dis(np, r);
            if(res > ndis && Check(np)) {
                OK = true;
                res = ndis;
            }
        }
    }
    return OK;
}
int main() {

    while(~scanf("%lf %lf %lf", &x, &y, &d)) {
        r.x = x, r.y = y;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        double res;
        if(Check1()) {
            puts("0.00");
        }
        else if(Check2(res)) {
            printf("%.2f\n", res);
        }
        else if(Check3(res)) {
            printf("%.2f\n", res);
        }
        else {
            puts("X");
        }
    }
    return 0;
}
