#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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
    int cntu, cntv;
    int c;
} E[N*2];
int head[N];
int cnt[N];
int nedge;

void add_edge(int u, int v, int c) {
    E[nedge].u = u;
    E[nedge].v = v;
    E[nedge].c = c;
    E[nedge].cntu = E[nedge].cntv = 0;
    E[nedge].pre = head[u];
    head[u] = nedge++;
}
void init() {
    nedge = 0;
    memset(head, -1, sizeof(head));
}
int n;
void dfs(int u, int pre) {
    cnt[u] = 1;
    for(int e = head[u]; ~e; e = E[e].pre) {
        int v = E[e].v;
        if(v == pre)continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        E[e].cntv = cnt[v];
        E[e].cntu = n - cnt[v];
    }
    //printf("cnt[%d]=%d\n", u, cnt[u]);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        init();
        scanf("%d", &n);
        int u, v, c;
        for(int i = 1; i < n; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        memset(cnt, 0, sizeof(cnt));
        dfs(1, 1);
        LL res = 0;
        for(int i = 0; i < nedge; ++i) {
            //printf("%d,%d    %d %d\n", E[i].u, E[i].v,  E[i].cntu, E[i].cntv);
            res += (LL)2*E[i].c * min(E[i].cntu, E[i].cntv);
        }
        printf("Case #%d: %I64d\n", t, res);
    }
    return 0;
}
