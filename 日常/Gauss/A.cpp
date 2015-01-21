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
int u[N], v[N];
int n;
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
    return 0;
}
void pf() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            printf("%d ", a[i][j]);
        } puts("");
    }
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 6;
}


int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int val;
        int m = 0;
        n = 30;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 6; ++j) {
                scanf("%d", &val);
                a[m++][n] = val;
            }
        }
        //pf();

        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 6; ++j) {
                int p = i * 6 + j;
                int q = p;
                a[p][q] = 1;
                for(int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(!in(nx, ny))continue;
                    p = nx * 6 + ny;
                    a[p][q] = 1;
                }
            }
        }
        gauss();
        m = 0;
        printf("PUZZLE #%d\n", t);
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 6; ++j) {
                printf("%d%c", as[m++], j == 5 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
