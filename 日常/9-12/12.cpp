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

const int N = 100005;
struct edge {
    int u, v, pre;
} E[N*2];

int head[N], cnt, n, m;
void add_edge(int u, int v) {
    E[cnt].u = u;
    E[cnt].v = v;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}
vector<int> f;
int mxdep, id;
bool vis[N];
void dfs(int u, int pre, int dep) {
    if(dep > mxdep) {
        mxdep = dep;
        id = u;
    }
    vis[u] = 1;
    for(int e = head[u]; ~e; e = E[e].pre) {
        int v = E[e].v;
        if(v != pre) {
            dfs(v, u, dep + 1);
        }
    }
}
int gao(int x, int y) {
    int ret = (x + 1) / 2 + (y + 1) / 2 + 1;
    checkmax(ret, x);
    checkmax(ret, y);
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &n, &m);
        int u, v;
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        memset(vis, false, sizeof(vis));
        f.clear();
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                id = -1, mxdep = -1;
                dfs(i, i, 0);
                dfs(id, id, 0);
                f.push_back(mxdep);
            }
        }
        LL res = f[0];
        for(int i = 1; i < f.size(); ++i) {
            res = gao(res, f[i]);
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
