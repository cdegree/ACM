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

const int maxn = 50005;

int tree[11][11][maxn], v[maxn];

void update(int a, int b, int k, int c) {
    int p = a / k + 1;
    while(p < maxn) {
        tree[k][a%k][p] += c;
        p += (-p & p);
    }
    p =  a / k + (b - a) / k + 2;
    while(p < maxn) {
        tree[k][a%k][p] -= c;
        p += (-p & p);
    }
}

int get_sum(int p) {
    int sum = 0;
    for(int i = 1; i <= 10; ++i) {
        int q = p / i + 1;
        while(q > 0) {
            sum += tree[i][p%i][q];
            q -= (-q & q);
        }
    }
    return sum;
}


int main() {
    int n, q, tp, a, b, k, c;
    while(~scanf("%d", &n)) {
        memset(tree, 0, sizeof(tree));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", v + i);
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%d", &tp);
            if(tp == 1) {
                scanf("%d%d%d%d", &a, &b, &k, &c);
                update(a, b, k, c);
            }
            else {
                scanf("%d", &a);
                printf("%d\n", get_sum(a) + v[a]);
            }
        }
    }
    return 0;
}
