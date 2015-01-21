/********************

Road to Investor

Author:Cdegree

********************/
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

const double eps = 1e-12;
const int N = 10005;

struct edge {
    int u, v, s, l, pre, id;
} E[N*2];

int nedge, head[N];

void add_edge(int u, int v, int s, int l, int id) {
    E[nedge].u = u;
    E[nedge].id = id;
    E[nedge].v = v;
    E[nedge].s = s;
    E[nedge].l = l;
    E[nedge].pre = head[u];
    head[u] = nedge++;
}
bool vis[N];
double dis[N];
int pre[N], pree[N];
int res[N];
int n, m, T;
bool spfa(double over) {
    queue<int> Q;
    Q.push(1);
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i <= n; ++i)dis[i] = 1e9;
    vis[1] = 1;
    dis[1] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        for(int e = head[u]; ~e; e = E[e].pre) {
            int v = E[e].v;
            double limit = E[e].s;
            double L = E[e].l;
            if(dis[v] > dis[u] + L / (limit + over)) {
                dis[v] = dis[u] + L / (limit + over);
                pre[v] = u;
                pree[v] = e;
                if(!vis[v]) {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    return dis[n] <= T + eps;
}

void output(int n, int m) {
    if(~pre[n]) {
        output(pre[n], m);
        printf("%d%c", E[pree[n]].id, n == m ? '\n' : ' ');
    }
}
int main() {

    while(~scanf("%d%d", &n, &m)) {
        memset(head, -1, sizeof(head));
        nedge = 0;
        for(int i = 0; i < m; ++i) {
            int u, v, s, l;
            scanf("%d %d %d %d", &u, &v, &s, &l);
            add_edge(u, v, s, l, i + 1);
            add_edge(v, u, s, l, i + 1);
        }
        scanf("%d", &T);
        double l = 0, r = 1e8, mid, ans;
        for(int i = 0; i < 100; ++i) {
            mid = (l + r) / 2;
            //printf("mid = %.6f\n",mid);
            if(spfa(mid)) {
                ans = mid;
                r = mid;
            }
            else {
                l = mid;
            }
        }
        int cnt = 0;
        int now = n;
        while(~pre[now]) {
            ++cnt;
            now = pre[now];
        }
        printf("%.6f %d\n", ans, cnt);
        output(n, n);
    }
    return 0;
}
