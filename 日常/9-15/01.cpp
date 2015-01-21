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

const int N = 1005;
const int M = N * N * 2;
struct edge {
    int u, v, w, pre;
} E[M];

int head[N], cnt, dfn[N], low[N];
void add_edge(int u, int v, int w) {
    E[cnt].u = u;
    E[cnt].v = v;
    E[cnt].w = w;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}
int instack[N];
void init() {
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(instack, 0, sizeof(instack));
    cnt = 0;
}
bool vis[1005];
int ccnt = 0;
void dfs1(int u, int pre) {
    vis[u] = 1;
    ++ccnt;
    for(int e = head[u]; ~e; e = E[e].pre) {
        int v = E[e].v;
        if(!vis[v]) {
            dfs1(v, u);
        }
    }
}
int tims;
int res;

void dfs2(int u, int pre, int pre_e) {
    dfn[u] = low[u] = ++tims;
    instack[u] = 1;
    for(int e = head[u]; ~e; e = E[e].pre) {
        if(e == pre_e)continue;
        int v = E[e].v;
        if(dfn[v] == -1) {
            dfs2(v, u, e ^ 1);
            low[u] = min(low[u], low[v]);
            if(low[u] < low[v]) {
                checkmin(res, E[e].w);
            }
        }
        else if(instack[v] && low[u] > dfn[v]) {
            low[u] = dfn[v];
        }

    }
}

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0)break;
        int u, v, w;
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        memset(vis, 0, sizeof(vis));
        ccnt = 0;
        dfs1(1, 1);
        if(ccnt != n) {
            puts("0");
        }
        else {
            tims = 0;
            res = 2e9;
            dfs2(1, 1, -1);
            if(res != 2e9) {
                if(res == 0)++res;
                printf("%d\n", res);
            }
            else {
                puts("-1");
            }
        }
    }
    return 0;
}
