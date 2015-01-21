/********************

Author:Cdegree

********************/
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


int val[7][105][105];


int main() {
    int n;
    while(~scanf("%d", &n)) {
        int m = 6 * n * n;
        int p = 1;
        for(int k = 1; k <= 2; ++k)
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    val[k][i][j] = p;
                    val[k+2][n-i+1][j] = m - p+1;
                    ++p;
                }
            }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                val[5][i][j] = p;
                val[6][n-i+1][j] = m - p+1;
                ++p;
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                printf("%d%c", val[5][i][j], j == n ? '\n' : ' ');
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int k = 1; k <= 4; ++k)
                for(int j = 1; j <= n; ++j) {
                    printf("%d%c", val[k][i][j], k == 4&&j==n ? '\n' : ' ');
                }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                printf("%d%c", val[6][i][j], j == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
