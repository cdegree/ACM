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


const int N = 50005;
const int E = 1000005;
const int inf = 1000000000;
struct Edge {
    int en, cap, flow, next;
} edge[E];
int head[N] , now[N];
int src, dest, node, nedge;
int pre[N] , dis[N] , gap[N];

void add_edge(int st, int en, int cap) {
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

void augment(int flow) {
    for(int i = src; i != dest; i = edge[now[i]].en) {
        edge[now[i]].flow += flow;
        edge[now[i] ^ 1].flow -= flow;
    }
}

int sap() {
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < node; i++)
        now[i] = head[i];
    gap[0] = node;
    int point = src, flow = 0, min_flow = inf;
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

char s[202];
int main() {
    int n, f, d;
    while(~scanf("%d%d%d", &n, &f, &d)) {
        init(n + n + f + d + 2, 0, n + n + f + d + 1);
        int v;
        for(int i = 1; i <= f; ++i) {
            scanf("%d", &v);
            add_edge(src, i, v);
        }
        for(int i = 1; i <= d; ++i) {
            scanf("%d", &v);
            add_edge(n + n + f + i, dest, v);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for(int j = 0; j < f; ++j) {
                if(s[j] == 'Y') {
                    add_edge(j + 1, f + i, 1);
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for(int j = 0; j < d; ++j) {
                if(s[j] == 'Y') {
                    add_edge(f + n + i, f + n + n + j + 1, 1);
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            add_edge(f + i, f + n + i, 1);
        }
        int res = sap();
        printf("%d\n", res);
    }
    return 0;
}
