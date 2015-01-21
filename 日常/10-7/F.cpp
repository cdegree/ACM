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
double get_dis(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double get_pdis(point p, point l1, point l2) {
    point v = ptoline(p, l1, l2);
    return get_dis(v, p);
}

double dp[105];
int D;
double eps = 1e-7;
point P[105];
bool OK(int from, int to, point l1, point l2) {
    bool ok = 1;
    for(int i = from; i <= to; ++i) {
        if(get_pdis(P[i], l1, l2) > D + eps) {
            ok = 0;
        }
    }
    return ok;
}

int main() {
    int n;
    while(~scanf("%d%d", &n, &D)) {
        if(n == 0 && D == 0)break;
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        for(int i = 0; i < n; ++i) {
            dp[i] = 1e9;
        }
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(OK(j, i, P[i], P[j])) {
                    dp[i] = min(dp[i], dp[j] + get_dis(P[i], P[j]));
                }
            }
        }
        printf("%.2f\n", dp[n-1]);
    }
    return 0;
}
