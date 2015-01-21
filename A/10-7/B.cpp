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
    int u, v, pre;
} E[N*12];

int head[N], cnt;

void add_edge(int u, int v) {
    E[cnt].u = u;
    E[cnt].v = v;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}

void init() {
    int cur = 1;
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j < N; ++j)
        }
}

int main() {
    init();
    return 0;
}
