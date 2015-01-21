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
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

const int N = 1005;
struct edge {
    int u, v;
    char tp;
    bool choose;
    int pre;
} E[N*N*2];
int cnt, head[N];
void add_edge(int u,int v,char c)
{
    E[cnt].tp=c;
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    E[cnt].choose=false;
    head[u]=cnt++;
}
int Set[N];
int Find_Set(int x) {
    if(x == Set[x])return x;
    return Set[x] = Find_Set(Set[x]);
}
void Union_Set(int x, int y) {
    Set[Find_Set(y)] = Find_Set(x);
}
vector<int> unchoose;

bool vis[2002];
int find(int st, int ed, char tp) {
    queue<int> Q;
    Q.push(st);
    memset(vis, false, sizeof(vis));
    while(!Q.empty()) {
        int u = Q.front();

    }
}

int main() {
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k)) {
        if(n == 0 && m == 0 && k == 0)break;
        char s[2];
        int u,v;
        for(int i = 0; i < m; ++i) {
            scanf("%s%d%d", s, &u, &v);
            add_edge(u,v,s[0]);
            add_edge(v,u,s[0]);
        }

        for(int i = 1; i <= n; ++i)Set[i] = i;

        int q = 0;
        int bcnt = 0;
        unchoose.clear();
        for(int i = 0; i < m; i) {
            int x = Find_Set(E[i].u);
            int y = Find_Set(E[i].v);
            if(x == y) {
                unchoose.push_back(i);
                continue;
            }
            if(E[i].tp == 'B') {
                ++bcnt;
                ++q;
                Union_Set(x, y);
            }
            else {
                ++q;
                Union_Set(x, y);
            }
            E[i].choose = true;
        }
        if(bcnt < k) {

        }
        else {

        }
    }

    return 0;
}
