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
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

LL x[1000005], dp[1000005];
LL n, c;
const double eps = 1e-7;
double get_y(int j, int i) {
    return log(dp[j] + c + sqr(x[j+1] - x[i]) + eps);
}

double get_p(int i, int j) {
    return (dp[i] - dp[j] + sqr(x[i+1]) - sqr(x[j+1])) / (2.0 * (x[i+1] - x[j+1]));
}

int q[1000005];

int main() {
    while(~scanf("%I64d%I64d", &n, &c)) {
        if(n == 0 && c == 0)break;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", x + i);
        }
        dp[0] = 0;
        q[0] = 0;
        int front = 0, tail = 0;
        for(int i = 1; i <= n; ++i) {
            while(front < tail && get_y(q[front+1], i) < get_y(q[front], i))++front;
            dp[i] = dp[ q[front] ] + c + sqr(x[ q[front] + 1 ] - x[ i ]);
            while(front < tail && (get_y(i,i) < get_y(q[tail],i) ||  (get_y(i,i) >= get_y(q[tail],i) && get_y(q[tail],i)  )  )    )     --tail;
            q[++tail] = i;
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
