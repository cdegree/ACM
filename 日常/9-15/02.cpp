Íõ¹Ú»ª(835250650) 13: 48: 27
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

#define INFINITE 1000000000
#define OPPOSITE(x) ((((x) - 1) ^ 1) + 1)
#define MIN(a,b)((a)<(b)?(a):(b))
#define MAXM 1000000
#define MAXN 50000

using namespace std;
typedef long long ll;

int g[MAXN] , cur[MAXN] , end[MAXM] , c[MAXM] , tot = 0 , next[MAXM];
int a[MAXN];
int pre[MAXN];
int sumd[MAXN] , d[MAXN] ;
int S , T  ;

void AddEdge(int x , int y , int flow) {
    ++tot ;
    next[tot] = g[x] ;
    g[x] = tot ;
    end[tot] = y ;
    c[tot] = flow ;
    ++tot ;
    next[tot] = g[y] ;
    g[y] = tot ;
    end[tot] = x ;
    c[tot] = 0 ;
}

int Sap() {
    int u, now, tmp, flow = 0;
    int v = T + 1 ;
    a[u=S] = INFINITE, sumd[0] = v;
    for(int i = 0 ; i < v; i++)
        cur[i] = g[i];
    while(d[S] < v) {
        for(now = cur[u]; now; now = next[now])
            if(c[now] && d[u] == d[end[now]] + 1)
                break;
        if(now) {
            tmp = end[now];
            a[tmp] = MIN(a[u], c[now]);
            cur[u] = pre[tmp] = now;
            if((u = tmp) == T) {
                flow += (tmp = a[T]);
                do {
                    c[pre[u]] -= tmp;
                    c[OPPOSITE(pre[u])] += tmp;
                    u = end[OPPOSITE(pre[u])];
                }
                while(u != S);
                a[S] = INFINITE;
            }
        }
        else {
            if((-- sumd[d[u]]) == 0)
                break;
            d[u] = v;
            cur[u] = g[u];
            for(now = g[u]; now; now = next[now])
                if(c[now] && d[u] > d[end[now]] + 1)
                    d[u] = d[end[now]] + 1, cur[u] = now;
            sumd[d[u]] ++;
            if(u != S)
                u = end[OPPOSITE(pre[u])];
        }
    }
    return flow;
}
struct wgh {
    int x, y;
} aa[MAXN];
int x, y, num, n;
int dd[][2] = {0, 1, 1, 0, 1, 1};
vector<int>v[211][211];
int b[11];
void dfs(int u, int x, int y, int k) {
    if(u >= 3) {
        num++;
        AddEdge(b[0], num, 1);
        AddEdge(b[1], num, 1);
        AddEdge(b[2], num, 1);
        AddEdge(b[3], num, 1);
        AddEdge(num, T, 4);
        return;
    }
    int xx = x + dd[u][0] * k;
    int yy = y + dd[u][1] * k;
    int i, j;
    for(i = 0; i < v[xx][yy].size(); i++) {
        b[u] = v[xx][yy][i];
        dfs(u + 1, x, y, k);
    }
}
int main() {
    int i, j;
    while(scanf("%d", &n) != EOF) {
        if(n == -1)break;
        memset(g, 0, sizeof(g));
        memset(c, 0, sizeof(c));
        memset(sumd, 0, sizeof(sumd));
        memset(cur, 0, sizeof(cur));
        memset(end, 0, sizeof(end));
        memset(pre, 0, sizeof(pre));
        memset(d, 0, sizeof(d));

        for(i = 1; i <= 101; i++)
            for(j = 1; j <= 101; j++)v[i][j].clear();
        tot = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d%d", &aa[i].x, &aa[i].y);
            v[aa[i].x][aa[i].y].push_back(i);
        }
        S = 0;
        T = MAXN - 10;
        num = n;
        for(i = 1; i <= n; i++) {
            AddEdge(S, i, 1);
            x = aa[i].x;
            y = aa[i].y;
            for(j = 1; j <= 100; j++) {
                memset(b, 0, sizeof(b));
                b[3] = i;
                dfs(0, x, y, j);
            }
        }
        printf("%d\n", Sap() / 4 * 4);
    }
}
