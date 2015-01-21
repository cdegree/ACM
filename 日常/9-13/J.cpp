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

int dp[105][505];
const int inf = 1e9;
bool vis[105];
int n, T;
const int N = 205;
struct edge {
    int v, pre, w;
} E[N];

int head[N], cnt;
void add_edge(int u, int v, int w) {
    E[cnt].v = v;
    E[cnt].w = w;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}

int dis[N], pre[N], cost[105][105], q[N];

void spfa(int x) {
    for(int i = 0; i < N; ++i)dis[i] = inf;
    queue<int> Q;
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    Q.push(x);
    dis[x] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        for(int e = head[u]; ~e; e = E[e].pre) {
            int v = E[e].v;
            int w = E[e].w;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre[v] = u;
                q[v] = e;
                if(!vis[v]) {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    for(int i = n; i!=1; i = pre[i]) {
        //printf("%d -> %d\n", i, pre[i]);
        //printf("%d %d\n", E[ q[i] ].w, E[ q[i] ^ 1 ].w);
        E[ q[i] ].w = 0;
        E[ q[i] ^ 1 ].w = 0;
    }
}
int val[105];
void dfs(int u, int pre) {
    for(int i = 0; i <= T; ++i)dp[u][i] = val[u];
    for(int e = head[u]; ~e; e = E[e].pre) {
        int v = E[e].v;
        if(v == pre)continue;
        int c = E[e].w * 2;
        //printf("u = %d , v = %d ,c = %d\n",u,v,c);
        dfs(v, u);
        for(int i = T; i >= c; --i) {
            for(int j = i - c; j >= 0; --j) {
                dp[u][i] = max(dp[u][i], dp[u][j] + dp[v][i-j-c]);
            }
        }
    }
}


int main() {

    while(~scanf("%d%d", &n, &T)) {
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        for(int i = 1; i <= n; ++i)scanf("%d", val + i);

        spfa(1);
        if(dis[n] > T) {
            puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
        }
        else {
            T -= dis[n];
            dfs(1, 1);
            printf("%d\n", dp[1][T]);
        }

    }
    return 0;
}
