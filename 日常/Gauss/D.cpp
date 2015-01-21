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

const double eps = 1e-7;
const int N = 33;
int u[N], n;
bool l[N];
int a[N][N], as[N];
int gauss() {
    int i, j, k, r = 0;
    double tmp;
    for(i = 0; i < n; i++)
        l[i] = 0;
    for(i = 0; i < n; i++) {
        for(j = r; j < n; j++)
            if(a[j][i]) {
                for(k = i; k <= n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        if(a[r][i] == 0)continue;
        for(j = 0; j < n; j++)
            if(j != r && a[j][i]) {
                for(k = i; k <= n; k++)
                    a[j][k] ^= a[r][k];
            }
        l[i] = 1; r++;
    }
    for(i = 0; i < n; i++) {
        if(l[i]) {
            for(j = 0; j < n; j++)
                if(a[j][i])
                    as[i] = a[j][n];
        }
    }
    for(i = r; i < n; i++)if(a[i][n])return -1;
    return 1 << (n - r);
}
void pf() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            printf("%d ", a[i][j]);
            //printf("%.0f ", a[i][j]);
        } puts("");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", u + i);
        }
        int v;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &v);
            a[i][n] = u[i]^v;
            a[i][i] = 1;
        }
        int p, q;
        while(~scanf("%d%d", &p, &q), p || q) {
            a[q-1][p-1] = 1;
        }
        int res = gauss();
        if(~res) {
            printf("%d\n", res);
        }
        else {
            printf("Oh,it's impossible~!!\n");
        }
    }
    return 0;
}
