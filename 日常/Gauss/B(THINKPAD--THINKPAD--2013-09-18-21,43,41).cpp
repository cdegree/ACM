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
const int N = 255;
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
    //return 1 << (n - r);
}
void pf() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            printf("%d ", a[i][j]);
            //printf("%.0f ", a[i][j]);
        } puts("");
    }
}
char s[22];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int b[22][22];
int m;
bool in(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < m;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &m);
        n = m * m;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            for(int j = 0; j < m; ++j) {
                a[i*m+j][n] = ((s[j] == 'w') ? 1 : 0);
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                int p = i * m + j;
                int q = p;
                a[p][p] = 1;
                for(int k = 0; k < 4; ++k) {
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    if(in(nx, ny)) {
                        q = nx * m + ny;
                        a[p][q] = 1;
                    }
                }
            }
        }
        pf();
        int res = gauss();
        pf();
        if(~res) {
            printf("%d\n", res);
        }
        else {
            printf("inf\n");
        }
    }
    return 0;
}
