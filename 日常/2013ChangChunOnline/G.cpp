#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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


const int N = 105;
struct point {
    int x, y;
    point() {}
    void read() { scanf("%d%d", &x, &y); }
    point(int _x, int _y): x(_x), y(_y) {}
} a[N], b[N];


double dp[N];
int pre[N];
double dis[N][2];
double get_dis(point a, point b) {
    return sqrt(double(sqr(a.x - b.x)) + sqr(a.y - b.y));
}
void gao(int n) {
    int p = pre[n];
    if(p == 0) {
        for(int i = n; i > p; --i) {
            if(i != n)putchar(' ');
            printf("%d+", i);
        }
        for(int i = p + 1; i <= n; ++i) {
            printf(" %d-", i);
        }
    }
    else {
        gao(p);
        for(int i = n; i > p; --i) {
            printf(" %d+", i);
        }
        for(int i = p + 1; i <= n; ++i) {
            printf(" %d-", i);
        }
    }


}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            a[i].read();
            b[i].read();
        }
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = 1e20;
            //printf("%d:\n",i);
            for(int j = 1; j <= i; ++j) {
                double sum = get_dis(a[j], b[j]);
                for(int k = j; k < i; ++k) {
                    sum += get_dis(a[k], a[k+1]);
                    sum += get_dis(b[k], b[k+1]);
                }
                sum += get_dis(b[j-1],a[i]);
                //printf("from %d to %d = %f\n",j,i,sum);
                //printf(" %f  compare to  %f + %f(%d) = %f\n", dp[i], sum,dp[j-1],j-1,sum+dp[j-1]);
                if(sum + dp[j-1]  < dp[i]) {
                    pre[i] = j - 1;
                    dp[i] = sum + dp[j-1];
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            //printf(" pre[%d] = %d  dp[%d] = %f\n",i,pre[i],i,dp[i]);
        }
        gao(n);
        puts("");
    }
    return 0;
}
