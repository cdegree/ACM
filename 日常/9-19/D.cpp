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
const LL inf = 1LL << 56;
const int N = 1010;
const int M = 1005000;
struct Edge {
    int st, en,   next;
    LL flow, cost, cap;
} E[M];
int head[N] , nedge , now[N], node;
int src, dest;
int pre[N];
LL dis[N];
queue<int> q;
bool vs[N];

void add_edge(int st, int en, LL cap, LL cost) {
    E[nedge].st = st;
    E[nedge].en = en;
    E[nedge].cap = cap;
    E[nedge].flow = 0;
    E[nedge].cost = cost;
    E[nedge].next = head[st];
    head[st] = nedge++;

    E[nedge].st = en;
    E[nedge].en = st;
    E[nedge].cap = 0;
    E[nedge].flow = 0;
    E[nedge].cost = -cost;
    E[nedge].next = head[en];
    head[en] = nedge++;
}

bool SPFA() {
    for(int i = 0; i < node; i++)
        dis[i] = inf;
    memset(vs, 0, sizeof(vs));
    memset(now, -1, sizeof(now));
    while(!q.empty()) q.pop();
    q.push(src); dis[src] = 0; vs[src] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop(); vs[u] = 0;
        for(int i = head[u], v; i != -1; i = E[i].next)
            if(E[i].cap - E[i].flow > 0 && dis[v=E[i].en] > dis[u] + E[i].cost) {
                dis[v] = dis[u] + E[i].cost;
                now[v] = i;
                if(!vs[v]) {
                    vs[v] = 1;
                    q.push(v);
                }
            }
    }
    if(dis[dest] != inf) return true;
    else return false;
}

void MCMF(LL &flow, LL &cost) {
    cost = 0, flow = 0;
    while(SPFA()) {
        LL fw = inf;
        for(int u = dest; u != src; u = E[now[u]].st)
            if(fw > E[now[u]].cap - E[now[u]].flow)
                fw = E[now[u]].cap - E[now[u]].flow;
        for(int u = dest; u != src; u = E[now[u]].st) {
            E[now[u]].flow += fw;
            E[now[u] ^ 1].flow -= fw;
        }
        flow += fw;
        cost += fw * dis[dest];
    }
}

void init(int _node, int _src, int _dest) {
    nedge = 0;
    node = _node;
    src = _src;
    dest = _dest;
    for(int i = 0; i < node; i++)head[i] = -1;
}

int e[N*N][2];
int gold[11], pri[N];
int main() {
    int T, n, m, k;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &e[i][0], &e[i][1]);
        }
        scanf("%d", &k);
        for(int i = 0; i < 2 * k; ++i) {
            scanf("%d", gold + i);
        }
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", pri + i);
            sum += pri[i];
        }
        LL res = inf;
        for(int mask = 0; mask < (1 << 2 * k); ++mask) {
            int cnt = 0;
            for(int i = 0; i < 2 * k; ++i) {
                if((mask >> i) & 1) {
                    ++cnt;
                }
            }
            if(cnt != k)continue;
            init(2 * n + 3, 2 * n + 1, 2 * n + 2);
            for(int i = 0; i < n; ++i) {
                add_edge(i, i + n, 1, pri[i]);
            }
            for(int i = 0; i < m; ++i) {
                add_edge(e[i][0] + n, e[i][1], inf, 0);
                add_edge(e[i][1] + n, e[i][0], inf, 0);
            }
            for(int i = 0; i < 2 * k; ++i) {
                if((mask >> i) & 1) {
                    add_edge(src, gold[i], 1, 0);
                }
                else {
                    add_edge(gold[i] + n, dest, 1, 0);
                }
            }
            LL cost, flow;
            MCMF(flow, cost);
            if(flow == k)res = min(res, cost);
        }
        if(res == inf) {
            puts("-1");
        }
        else {
            printf("%d\n", sum - res);
        }
    }
    return 0;
}
