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

const int N = 303;
struct point {
    LL x, y;
} P[N], st[N], p[N];

bool used[N];
bool cmp(point a, point b) {
    if(a.y != b.y)return a.y < b.y;
    return a.x < b.x;
}
inline LL xmult(point o, point a, point b) {
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
    sort(p, p + n, cmp);
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

LL cost[N][N];
LL dp[N][N];
int main() {
    int n;
    LL mod;
    while(~scanf("%d%lld", &n, &mod)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lld%lld", &P[i].x, &P[i].y);
            p[i] = P[i];
        }
        int len = graham(n);
        if(len != n) {
            puts("I can't cut.");
        }
        else {
            for(int i = 0; i < n; ++i) {
                for(int j = i+2; j < n; ++j) {
                    cost[j][i]= cost[i][j] = abs(st[i].x + st[j].x) * abs(st[i].y + st[j].y) % mod;
                }
            }
            LL inf = 1e18;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    dp[i][j] = inf;
                }
                dp[i][(i+1)%n] = 0;
            }
            for(int j = 2; j < n; ++j) {
                for(int i = j - 2; i >= 0; --i) {
                    for(int k = i + 1; k < j; ++k) {
                        checkmin(dp[i][j], dp[i][k] + dp[k][j] + cost[i][k] + cost[k][j]);
                    }
                }
            }
            printf("%lld\n", dp[0][n-1]);
        }
    }
    return 0;
}
