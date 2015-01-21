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

const int N = 20005;
int B[N];
struct edge {
    int u, v, pre;
} E[N*6];
int head[N], nedge, dfn[N], low[N], tsp, belong[N], num[N], cntnum, index;
bool instack[N];
int stk[N];
void add_edge(int u, int v) {
    E[nedge].u = u;
    E[nedge].v = v;
    E[nedge].pre = head[u];
    head[u] = nedge++;
}
int top;
void init() {
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    index = 0;
    top = 0;
    cntnum = 0;
    nedge = 0;
}
void tarjan(int u) {
    low[u] = dfn[u] = ++index;
    instack[u] = 1;
    stk[top++] = u;
    for(int e = head[u]; ~e; e = E[e].pre) {
        int v = E[e].v;
        if(dfn[u] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v] && dfn[v] < low[u]) {
            low[u] = dfn[v];
        }
    }
    int v;
    if(dfn[u] == low[u]) {
        do {
            v = stk[--top];
            belong[v] = cntnum;
            instack[v] = 0;
        }
        while(v != u);
        cntnum++;
    }
}
bool solve(int n) {
    for(int i = 0; i < 2 * n; ++i) {
        if(dfn[i] == -1) {
            tarjan(i);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(belong[i] == belong[i+n]) {
            return false;
        }
    }
    return true;
}
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%d", B + i);
            --B[i];
        }
        init();
        for(int i = 0; i < m; ++i) {
            int a, b, tp, id1, id2;
            scanf("%d %d %d", &id1, &id2, &tp);
            --id1, --id2;
            a = B[id1];
            b = B[id2];
            //printf("%d -> %d\n", a, b);
            if((a + 1) % 3 == b) {
                if(tp) {
                    add_edge(id1 + n, id2 + n);
                    add_edge(id2, id1);
                }
                else {
                    add_edge(id1, id1 + n);
                    add_edge(id2 + n, id2);
                    add_edge(id1 + n, id2);
                    add_edge(id2, id1 + n);
                }
            }
            else if((b + 1) % 3 == a) {
                if(tp) {
                    add_edge(id1, id2);
                    add_edge(id2 + n, id1 + n);
                }
                else {
                    add_edge(id1 + n, id1);
                    add_edge(id2, id2 + n);
                    add_edge(id1, id2 + n);
                    add_edge(id2 + n, id1);
                }
            }
            else if(a == b) {
                if(tp) {
                    add_edge(id1, id2 + n);
                    add_edge(id2 + n, id1);
                    add_edge(id1 + n, id2);
                    add_edge(id2, id1 + n);
                }
                else {
                    add_edge(id1, id2);
                    add_edge(id2, id1);
                    add_edge(id1 + n, id2 + n);
                    add_edge(id2 + n, id1 + n);
                }
            }
            else while(1);
        }
        printf("Case #%d: ", t);
        if(solve(n)) {
            puts("yes");
        }
        else {
            puts("no");
        }
    }
    return 0;
}
