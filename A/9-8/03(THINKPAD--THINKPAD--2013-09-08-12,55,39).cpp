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

int a[11][11];
pair<int, int> turn(pair<int, int> p, int n) {
    pair<int, int> ret;
    ret.X = p.Y;
    ret.Y = n - 1 - p.X;
    return ret;
}


LL get_sum(int x, int y, int n) {
    pair<int, int> p = make_pair(x, y);
    pair<int, int> np = p;
    LL sum = 0;
    sum += a[ np.X ][ np.Y ];
    np = turn(np, n);

    while(np != p) {
        sum += a[ np.X ][ np.Y ];
        np = turn(np, n);
    }
    return sum;
}

struct wati {
    LL sum;
    LL cost;
} W[22];
int len;
bool cmp(wati a, wati b) {
    if(a.sum != b.sum)return a.sum > b.sum;
    return a.cost < b.cost;
}
int main() {
    int n;
    while(~scanf("%d", &n), n) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        LL res1 = a[n/2][n/2], res2 = 0;
        for(int i = 0; i <  n / 2; ++i) {
            int limit = (n + 1) / 2;
            len = 0;
            for(int j = i; j < limit; ++j) {
                W[len].sum = get_sum(i, j, n);
                W[len++].cost = j - i;
            }
            sort(W, W + len, cmp);
            res1 += W[0].sum;
            res2 += W[0].cost;
        }
        printf("%I64d %I64d\n", res1, res2);

    }
    return 0;
}
