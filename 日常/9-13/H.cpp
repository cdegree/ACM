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

const int N = 10005;
struct edge {
    int v, pre;
} E[N];

int head[N], cnt;
void add_edge(int u, int v) {
    E[cnt].v = v;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}
const LL inf = 2e16;
struct node {
    LL up, low;
} nd[N];

bool contradict(node a, node b) {
    return a.up < b.low || b.up < a.low;
}

void merge(node &a, node b) {
    a.up = min(a.up, b.up);
    a.low = max(a.low, b.low);
}
bool OK;
void dfs(int u) {
    node tmp;
    tmp.low = 1, tmp.up = inf;
    for(int e = head[u]; ~e; e = E[e].pre) {
        int v = E[e].v;
        dfs(v);
        tmp.low += nd[v].low;
    }
    if(!contradict(nd[u], tmp)) {
        merge(nd[u], tmp);
    }
    else {
        OK = 0;
    }
}

int main() {
    int n, m;
    while(~scanf("%d", &n)) {
        int v, u;
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 2; i <= n; ++i) {
            scanf("%d", &u);
            add_edge(u, i);
        }
        for(int i = 1; i <= n; ++i) {
            nd[i].up = inf;
            nd[i].low = 1;
        }
        scanf("%d", &m);
        int d, w;
        char s[2];
        OK = 1;
        for(int i = 0; i < m; ++i) {
            scanf("%d%s%d", &d, s, &w);
            node tmp;
            if(s[0] == '=') {
                tmp.low = tmp.up = w;
            }
            else if(s[0] == '<') {
                tmp.low = 1, tmp.up = w - 1;
            }
            else {
                tmp.low = w + 1, tmp.up = inf;
            }
            if(!contradict(nd[d], tmp)) {
                merge(nd[d], tmp);
            }
            else OK = 0;
        }
        dfs(1);
        printf("%s\n", OK ? "True" : "Lie");
    }
    return 0;
}
