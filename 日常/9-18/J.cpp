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

typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

int n, m, val;
const int N = 20005;
const int E = 300005;
const LL inf = 1e17;
struct Edge {
    int en, next;
    LL cap, flow;
} edge[E];
int head[N] , now[N];
int src, dest, node, nedge;
int pre[N] , dis[N] , gap[N];

void add_edge(int st, int en, LL cap) {
    edge[nedge].en = en;
    edge[nedge].cap = cap;
    edge[nedge].flow = 0;
    edge[nedge].next = head[st];
    head[st] = nedge++;

    edge[nedge].en = st;
    edge[nedge].cap = 0;
    edge[nedge].flow = 0;
    edge[nedge].next = head[en];
    head[en] = nedge++;
}

void augment(LL flow) {
    for(int i = src; i != dest; i = edge[now[i]].en) {
        edge[now[i]].flow += flow;
        edge[now[i] ^ 1].flow -= flow;
    }
}

LL sap() {
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < node; i++)
        now[i] = head[i];
    gap[0] = node;
    int point = src;
    LL flow = 0;
    LL min_flow = inf;
    while(dis[src] < node) {
        bool fg = false;
        for(int i = now[point]; ~i; i = edge[i].next)
            if(edge[i].cap - edge[i].flow > 0 && dis[point] == dis[edge[i].en] + 1) {
                min_flow = min(min_flow, edge[i].cap - edge[i].flow);
                now[point] = i;
                pre[edge[i].en] = point;
                point = edge[i].en;
                if(point == dest) {
                    flow += min_flow;
                    augment(min_flow);
                    point = src;
                    min_flow = inf;
                }
                fg = true;
                break;
            }
        if(fg) continue;
        if(--gap[dis[point]] == 0) break;
        int Min = node;
        for(int i = head[point]; ~i; i = edge[i].next)
            if(edge[i].cap - edge[i].flow > 0 && Min > dis[edge[i].en]) {
                Min = dis[edge[i].en];
                now[point] = i;
            }
        gap[dis[point] = Min + 1]++;
        if(point != src) point = pre[point];
    }
    return flow;
}

void init(int _node, int _src, int _dest) {
    nedge = 0;
    node = _node;
    src = _src;
    dest = _dest;
    for(int i = 0; i < node; i++)head[i] = -1;
}

vector<int> L[N];
LL P[N], S[N];

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        for(int i = 0; i < N; ++i) {
            L[i].clear();
        }
        scanf("%d%d", &n, &m);
        int p;
        init(n + m + 2, 0, n + m + 1);
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &p);
            for(int j = 0; j < p; ++j) {
                scanf("%d", &val);
                add_edge(i, n + val, inf);
            }
            scanf("%I64d", P + i);
            sum += P[i];
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%I64d", S + i);
        }
        for(int i = 1; i <= n; ++i) {
            add_edge(src, i, P[i]);
        }
        for(int i = 1; i <= m; ++i) {
            add_edge(n + i, dest, S[i]);
        }
        sum -= sap();
        printf("Case %d: %I64d\n", t, sum);
    }
    return 0;
}
