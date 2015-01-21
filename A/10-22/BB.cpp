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

const int N = 105;
int st[N];

LL dis[N];
LL cost[N][N];
bool vis[N];
int n, k;

struct edge {
    int u, v, cost;
} E[N*N];

bool cmp(edge a,edge b)
{
    return a.cost<b.cost;
}
int Set[N];
int Find_Set(int x)
{
    if(x==Set[x])return x;
    return Set[x]=Find_Set(Set[x]);
}
bool powered(int x)
{
    for(int i=0;i<k;++i)
    {
        if(x==Find_Set(st[i]))
        {
            return true;
        }
    }
    return false;
}
int main() {
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 0; i < k; ++i) {
            scanf("%d", st + i);
            --st[i];
        }
        for(int i=0;i<n;++i)Set[i]=i;
        int len=0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%I64d", &cost[i][j]);
                E[len].u = i;
                E[len].v = j;
                E[len++].cost = cost[i][j];
            }
        }
        sort(E,E+len,cmp);
        LL res=0;
        for(int i=0;i<n*n;++i)
        {
            int u = E[i].u;
            int v = E[i].v;
            int c = E[i].cost;
            int x = Find_Set(u);
            int y = Find_Set(v);
            if(powered(x)&&powered(y))continue;
            if(x==y)continue;
            Set[x]=y;
            res += c;
        }
        printf("%I64d\n", res);
    }
    return 0;
}
