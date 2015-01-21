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
int x[N], free_x[N];
const int inf = 1e9;
int gauss() {
    int i, j, k, r = 0;
    int cnt = 0;
    for(i = 0; i <= n; ++i) {
        x[i] = free_x[i] = 0;
    }
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
            free_x[cnt++] = i;
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
    for(i = r; i < n; i++)if(a[i][n])return -1;
    /*
    int ret=0;
    for(int i=0;i<n;++i)ret+=as[i];
    return ret;
    */
    //puts("here");
    int stat = 1 << (n - r)  ; //自由变元 有 var - k 个
    int res = inf ;
    // 因为 自由变量的值可以影响 确定的变量的值 所以 要 枚举所有的可能 来确定最小值
    for(int i = 0 ; i < stat; ++i) { //枚举所有的 自由变量的状态
        int   cnt = 0;
        int  mask = i;
        for(j = 0; j < n - r ; j++) { //对 ，对应的自由变量 赋值
            x[free_x[j]] = (mask & 1);
            if(x[free_x[j]])cnt++;
            mask >>= 1;
        }
        for(j = r - 1 ; j >= 0; j--) { //带回 已经确定的变量，看是否 自由变量的 改变 影响 了其的值
            int tmp = a[j][n];
            for(int  l = j + 1; l < n; l++) {
                if(a[j][l])tmp ^= x[l] ;
            }
            x[j] = tmp ;
            if(x[j])cnt++;
        }
        if(cnt < res) res = cnt;
    }
    //printf("res = %d\n",res);
    return res;
}
void pf()
{
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            printf("%3d", a[i][j]);
        } puts("");
    }
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char s[6][6];
int main() {
    n = 16;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < 4; ++i) {
        scanf("%s", s[i]);
        for(int j = 0; j < 4; ++j) {
            a[ i*4+j ][n] = (s[i][j] == 'b') ? 1 : 0 ;
        }
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            int p = i * 4 + j;
            int q = p;
            a[p][q] = 1;
            for(int k = 0; k < 4; ++k) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
                    p = nx * 4 + ny;
                    a[p][q] = 1;
                }
            }
        }
    }
    pf();
    int res1 = gauss();
    pf();
    memset(a, 0, sizeof(a));
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            a[ i*4+j ][n] = (s[i][j] == 'w') ? 1 : 0 ;
        }
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            int p = i * 4 + j;
            int q = p;
            a[p][q] = 1;
            for(int k = 0; k < 4; ++k) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
                    p = nx * 4 + ny;
                    a[p][q] = 1;
                }
            }
        }
    }
    int res2 = gauss();
    if(res1==-1 && res2==-1) {
        puts("Impossible");

    }
    else
    {
        printf("%d\n", min(res1, res2));
    }
    return 0;
}
