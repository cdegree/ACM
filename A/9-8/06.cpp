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
int n, m, w;

int a[N];
double p[105][105], wc[105][105];
int res[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &w);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%lf", &p[i][j]);
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < w; ++j) {
                scanf("%lf", &wc[i][j]);
            }
        }
        int cur = 0;
        int len = 0;
        for(int d = 1; d <= n; ++d) {
            int ww = a[d];
            int pos = -1;
            double mx = 0;
            for(int j = 0; j < m; ++j) {
                double pi = wc[j][ww] * p[cur][j];
                //printf("d=%d,j=%d,pi=%.2f mx = %.2f\n",d,j,pi,mx);
                if(pi > mx) {
                    mx = pi;
                    pos = j;
                }
            }
            //printf("pos = %d\n",pos);
            res[len++] = pos;
            cur = pos;
        }
        for(int i = 0; i < len; ++i) {
            printf("%d%c", res[i],(i==len-1)?'\n':' ');
        }
    }
    return 0;
}
