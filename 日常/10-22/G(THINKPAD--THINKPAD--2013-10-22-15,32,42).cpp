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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int N = 100005;

struct NODE {
    int a, b;
    int id;
    int fa;
} nd[N];
int head[N],cnt;
struct edge
{
    int v,pre;
}E[N];
void add_edge(int u,int v)
{
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
int prert;
void gao(int rt, int x) {
    //printf("%d %d->%d %d\n",rt,nd[rt].a,nd[rt].b,x);
    if(nd[rt].a <= x && x <= nd[rt].b) {
        int n = nd[rt].chd.size();
        bool found = false;
        for(int i = 0; i < n; ++i) {
            int v = nd[rt].chd[i];
            if(nd[v].a <= x && x <= nd[v].b) {
                found = true;
                rt = v;
                gao(v, x);
                break;
            }
        }
        if(!found) {
            prert = rt;
            printf("%d\n", nd[rt].id);
        }
    }
    else {
        rt = nd[rt].fa;
        if(nd[rt].a <= x && x <= nd[rt].b) {
            prert = rt;
            printf("%d\n", nd[rt].id);
        }
        else gao(rt, x);
    }
}

int main() {
    int n, m;
    while(~scanf("%d", &n)) {
        int a, b;
        cnt=0;
        int len = 1;
        nd[0].a = 1, nd[0].b = 1e9, nd[0].id = -1;
        int pre = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            nd[len].a = a;
            nd[len].b = b;
            nd[len].id = i + 1;
            while(!(nd[pre].a <= a && b <= nd[pre].b)) {
                pre = nd[pre].fa;
            }
            nd[len].fa = pre;
            add_edge(pre,len);
            pre = len;
            len++;
        }
        scanf("%d", &m);
        int rt = 0;
        while(m--) {
            int x;
            scanf("%d", &x);
            gao(prert, x);
        }
    }
    return 0;
}
