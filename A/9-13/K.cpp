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
const double PI = acos(-1.0);
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}
using namespace std;



int v[16], p[3];
int sum = 0;
int n;

bool H1[1100][1100], H2[1100][1100], H3[1120][1120];
const int mod1 = 1019, mod2 = 1093, mod3 = 1097;
int res;

set<int> st[50000];

void dfs(int u, int a, int b, int c) {
    if(u == n) {
        if(a > b)swap(a, b);
        if(b > c)swap(b, c);
        if(a > b)swap(a, b);
        if(a + b > c) {
            if(st[a].find(b) == st[a].end()) {
                ++res;
                st[a].insert(b);
            }
        }
    }
    else {
        dfs(u + 1, a + v[u], b, c);
        dfs(u + 1, a, b + v[u], c);
        dfs(u + 1, a, b, c + v[u]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < 50000; ++i) {
            st[i].clear();
        }
        sum = 0;
        for(int i = 0; i < n; ++i) {scanf("%d", v + i); }
        res = 0;
        dfs(0, 0, 0, 0);
        //int res = hmp.size();
        printf("%d\n", res);
    }
    return 0;
}
