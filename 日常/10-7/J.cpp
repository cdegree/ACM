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

const int N = 40005;
struct edge {
    int u, v, pre;
    int op;
} E[N];

int head[N], cnt;

void add_edge(int u, int v, int _op) {
    E[cnt].op = _op;
    E[cnt].u = u;
    E[cnt].v = v;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}

int trap[N];
LL dp[N];
LL m;
void dfs(int u) {
    if(head[u] == -1) {
        return ;
    }
    LL ccnt[2];
    int v[2];
    int g = 0;
    int wc = -1;
    for(int e = head[u]; ~e; e = E[e].pre) {
        v[g] = E[e].v;
        dfs(v[g]);
        if(E[e].op == 1) {
            wc = g;
        }
        ++g;
    }
    if(wc == 0) {
        if(dp[ v[0] ] <= dp[ v[1] ]) {
            dp[u] += dp[ v[0] ] * 2;
            //dfs(v[0]);
        }
        else {
            dp[u] += dp[ v[1] ] * 2 + 1;
            //dfs(v[1]);
        }
    }
    else {
        if(dp[ v[1] ] <= dp[ v[0] ]) {
            dp[u] += dp[ v[1] ] * 2;
            //dfs(v[1]);
        }
        else {
            dp[u] += dp[ v[0] ] * 2 + 1;
            //dfs(v[0]);
        }
    }
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        if(n == 0)break;
        cnt = 0;
        memset(dp, 0, sizeof(dp));
        memset(head, -1, sizeof(head));
        memset(trap, 0, sizeof(trap));
        int p, f, t, rt;
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &p, &f, &t);
            dp[i] = t;
            if(p == 0) {
                rt = i;
            }
            else {
                add_edge(p, i, f);
            }
        }
        dfs(rt);
        printf("%lld\n", dp[rt]);
    }
    return 0;
}
