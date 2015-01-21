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

const int N = 1005;
int A[N], H[N];

struct gaiwu {
    int val;
    int tp;
} G[N*2];

bool cmp(gaiwu a, gaiwu b) {
    if(a.val != b.val)return a.val < b.val;
    return a.tp > b.tp;
}

int main() {
    int n;
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", A + i);
            G[i].val = A[i];
            G[i].tp = 0;
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", H + i);
            G[i+n].val = H[i];
            G[i+n].tp = 1;
        }
        sort(G, G + 2 * n, cmp);
        int cnt = 0, res = 0;
        for(int i = 0; i < 2 * n; ++i) {
            if(G[i].tp == 1) {
                ++cnt;
            }
            else if(cnt > 0) {
                ++res;
                --cnt;
            }
        }
        printf("Case %d: %d\n", t, res);
    }
    return 0;
}
