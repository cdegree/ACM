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
map<string, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int N = 30003;
char s[N][66];

int n;
map<string, int> mp;
struct node {
    int u;
    int fa;
    int dep;
    vector<int> son;
    string name;
} nd[N];

bool cmp(int a, int b) {
    return nd[a].name < nd[b].name;
}

void dfs(int fa, int u, int dep) {
    nd[u].fa = fa;
    nd[u].u = u;
    nd[u].dep = dep;
    nd[u].name = &s[u][dep];
    mp[ nd[u].name ] = u;
    ++u;
    if(u == n + 1)return ;
    if(s[u][dep] == '.') {
        nd[u-1].son.push_back(u);
        dfs(u - 1, u, dep + 1);
    }
    else if(dep > 0 && s[u][dep-1] == '.') {
        nd[fa].son.push_back(u);
        dfs(fa, u, dep);
    }
    else {
        int v = fa;
        while(dep > 0 && s[u][dep-1] != '.') {
            --dep;
            v = nd[v].fa;
        }
        nd[v].son.push_back(u);
        dfs(v, u, dep);
    }
}
int Left[N*2], Right[N*2], R[N*2], E[N*2];
int cnt;
void dfs2(int u, int dep) {
    Left[u] = ++cnt;
    R[cnt] = u;
    E[cnt] = dep;
    for(int i = 0; i < nd[u].son.size(); ++i) {
        int v = nd[u].son[i];
        dfs2(v, dep + 1);
        R[++cnt] = u;
        E[cnt] = dep;
    }
    sort(nd[u].son.begin(), nd[u].son.end(), cmp);
}
void dfs3(int u, int dep) {
    for(int i = 0; i < dep; ++i)putchar('.');
    printf("%s\n", nd[u].name.c_str());

    for(int i = 0; i < nd[u].son.size(); ++i) {
        int v = nd[u].son[i];
        dfs3(v, dep + 1);
    }
}
char ch[2];
char t1[66], t2[66];
const int maxn = N * 2;
int dp_min[maxn][33];
void rmq_init(int *c, int n) {
    for(int i = 1; i <= n; i++)dp_min[i][0] = i;
    double limit = log(1.0 * n) / log(2.0);
    for(int j = 1; j <= (int)limit; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            if(c[ dp_min[i][j-1]  ] < c[ dp_min[i+(1<<(j-1))][j-1] ])dp_min[i][j] = dp_min[i][j-1];
            else dp_min[i][j] = dp_min[i+(1<<(j-1))][j-1];
        }
}
int get_min(int a, int b) {
    int k = (int)(log(b - a + 1.0) / log(2.0));
    if(E[dp_min[a][k]] < E[dp_min[b-(1<<k)+1][k]])return dp_min[a][k];
    else return dp_min[b-(1<<k)+1][k];
}

int query(int i, int j) {
    if(i > j)swap(i, j);
    return get_min(i, j);
}
int main() {

    while(~scanf("%d", &n), n) {
        mp.clear();
        for(int i = 0; i < N; ++i)nd[i].son.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i]);
        }
        dfs(-1, 1, 0);
        cnt = 0;
        dfs2(1, 0);
        rmq_init(E, 2 * n - 1);
        int q;
        scanf("%d", &q);
        while(q--) {
            scanf("%s", ch);
            if(ch[0] == 'L') {
                dfs3(1, 0);
            }
            else if(ch[0] == 'b') {
                scanf("%s", t1);
                string tmp = t1;
                int u = mp[tmp];
                if(u == 1)puts("1");
                else printf("%d\n", nd[nd[ u ].fa].son.size());
            }
            else {
                scanf("%s %s", t1, t2);
                string tmp1 = t1, tmp2 = t2;
                int u = mp[tmp1], v = mp[tmp2];
                u = Left[nd[u].fa] , v = Left[nd[v].fa];
                int p = R[query(u, v)];
                printf("%s\n", nd[p].name.c_str());
            }
        }
    }
    return 0;
}
