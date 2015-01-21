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
} P[22], st[22], p[22];

bool used[22];
bool cmp(point a, point b) {
    if(a.y != b.y)return a.y < b.y;
    return a.x < b.x;
}
inline double xmult(point o, point a, point b) {
    point v1, v2;
    v1.x = a.x - o.x;
    v1.y = a.y - o.y;
    v2.x = b.x - o.x;
    v2.y = b.y - o.y;
    return v1.x * v2.y - v2.x * v1.y;
}
int graham(int n) {
    int top;
    top = 0;
    st[top++] = p[0];
    st[top++] = p[1];

    for(int i = 2; i < n; i++) {
        while(top >= 2 && xmult(p[i], st[top - 1], st[top - 2]) >= 0)
            top--;
        st[top++] = p[i];
    }
    int tmp = top;
    for(int i = n - 2; i >= 0; i--) {
        while(top != tmp && xmult(p[i], st[top - 1], st[top - 2]) >= 0)
            top--;
        st[top++] = p[i];
    }
    top--;
    return top;
}
inline double get_dis(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double res;
void init(int n) {

    int m = 0;
    for(int i = 0; i < n; ++i) {
        if(used[i]) {
            p[m++] = P[i];
        }
    }
    if(m < 3)return ;
    n = graham(m);
    if(n < 3)return ;
    double len = 0, S = 0;
    for(int i = 0; i < n; ++i) {
        len += get_dis(st[i], st[i+1]);
    }
    for(int i = 1; i < n; ++i) {
        S += xmult(st[0], st[i], st[i+1]);
    }
    S = fabs(S / 2);
    checkmin(res, len * len / S);
}
void dfs(int u, int n) {
    if(u == n) {
        init(n);
    }
    else {
        dfs(u + 1, n);
        used[u] = 1;
        dfs(u + 1, n);
        used[u] = 0;
    }
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }
        sort(P, P + n, cmp);
        memset(used, 0, sizeof(used));
        res = 2e18;
        dfs(0, n);
        printf("%.4f\n", res);
    }
    return 0;
}
