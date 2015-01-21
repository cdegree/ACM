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

const int N = 100008;
double p[N], e[N];
int n, m;
int next[N];
bool jump[N];

int main() {
    while(1) {
        memset(next, -1, sizeof(next));
        memset(p, 0, sizeof(p));
        memset(e, 0, sizeof(e));
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0)break;
        int X, Y;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &X, &Y);
            next[X] = Y;
        }

        p[0] = 1, e[1] = 0;
        for(int i = 0; i < n; ++i) {
            if(~next[i]) {
                e[ next[i] ] += e[i];
                p[ next[i] ] += p[i];
            }
            else {
                for(int j = 1; j <= 6; ++j) {
                    e[i+j] += (e[i] + p[i]) / 6.0;
                    p[i+j] += p[i] / 6;
                }
            }
        }
        double res = 0;
        for(int i = n; i < n + 6; ++i) {
            res += e[i];
        }
        printf("%.4f\n", res);
    }
    return 0;
}
