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
const int N = 255;
int u[N];
bool l[N];
int a[N][N], as[N], x[N], free_x[N];
const int inf = 1e9;
int gauss(int n) {
    int i, j, k, r = 0;
    double tmp;
    int cnt=0;
    for(i = 0; i < n; i++)
        l[i] = 0;
    for(i = 0; i < n; i++) {
        for(j = r; j < n; j++)
            if(a[j][i]) {
                for(k = i; k <= n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        if(a[r][i] == 0) {
            free_x[cnt++]=i;
            continue;
        }
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
    for(i = r; i < n; i++)if(a[i][n] == 0)return inf;
    puts("here");
    int stat = 1 << (n - k)  ; //自由变元 有 var - k 个
    int res = inf ;
    // 因为 自由变量的值可以影响 确定的变量的值 所以 要 枚举所有的可能 来确定最小值
    for(i = 0 ; i < stat; i++) { //枚举所有的 自由变量的状态
        int   cnt = 0;
        int  index = i;
        for(j = 0; j < n - k ; j++) { //对 ，对应的自由变量 赋值
            x[free_x[j]] = (index & 1);

            if(x[free_x[j]])cnt++;
            index >>= 1;
        }
        for(j = k - 1 ; j >= 0; j--) { //带回 已经确定的变量，看是否 自由变量的 改变 影响 了其的值
            int tmp = a[j][n];
            for(int  l = j + 1; l < n; l++) {
                if(a[j][l])tmp ^= x[l] ;
            }
            x[j] = tmp ;
            if(x[j])cnt++;
        }
        if(cnt < res) res = cnt;
    }
    return res;
}


int dx[][6] = { {0, 1, 0, -1, 0}, { -1, -1, 0,  0,  1} , { -1, -1, 0,  0, 1}, { -1, -1, 0,  1, 1}  };
int dy[][6] = { {1, 0, -1, 0, 0}, { -1, 0, -1,  1, -1},  { 0, 1, -1,  1, 0},  {  0,  1, -1,  0, 1}  };

char s[17][17];
int n, m;
inline bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
void pf() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            printf("%3d", a[i][j]);
        } puts("");
    }
}
int main() {

    while(~scanf("%d%d", &n, &m), n || m) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }
        int res = inf, pat = -1;
        int fn = n * m;

        for(int k = 0; k < 4; ++k) {
            memset(a, 0, sizeof(a));
            int p = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(s[i][j] == '1') {
                        a[p++][fn] = 1;
                    }
                    else {
                        a[p++][fn] = 0;
                    }
                    int x = i * m + j;
                    int y = x;
                    a[y][x] = 1;
                    for(int q = 0; q < 5; ++q) {
                        int nx = i + dx[k][q];
                        int ny = j + dy[k][q];
                        if(in(nx, ny)) {
                            y = nx * m + ny;
                            a[ y ][ x ] = 1;
                        }
                    }
                }
            }
            printf("p = %d\n", p);
            pf();
            int ans = gauss(fn);
            if(res > ans) {
                res = ans;
                pat = k;
            }
        }
        if(res == inf) {
            puts("Impossible");
        }
        else {
            printf("%d %d\n", pat + 1, res);
        }
    }
    return 0;
}
