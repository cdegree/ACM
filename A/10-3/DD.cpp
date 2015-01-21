/********************

Author:Cdegree

********************/
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
const int M = 200005;
int Set[N];

struct edge {
    int u, v;
} E[M];

int Find_Set(int x) {
    if(Set[x] == x)return x;
    return Set[x] = Find_Set(Set[x]);
}

int res[M];

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < N; ++i)Set[i] = i;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &E[i].u, &E[i].v);
        }
        int cnt = n;
        for(int i = m - 1; i >= 0; --i) {
            res[i] = cnt;
            int x = E[i].u;
            int y = E[i].v;
            int sx = Find_Set(x);
            int sy = Find_Set(y);
            if(sx == sy) {
            }
            else {
                Set[sy] = sx;
                --cnt;
            }
        }
        for(int i = 0; i < m; ++i) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}
