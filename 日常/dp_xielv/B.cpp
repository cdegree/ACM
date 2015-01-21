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

const int N = 50005;
LL dp[N], S[N], P[N];

double get_slope(int k, int j) {
    return (double)(dp[j] + sqr(S[j]) - dp[k] - sqr(S[k])) / (S[j] - S[k]);
}
LL n, L;
int c[N];
int deq[N];
int main() {
    while(~scanf("%lld %lld", &n, &L)) {
        S[0] = 0;

        for(int i = 1; i <= n; ++i) {
            scanf("%d", c + i);
            P[i] = P[i-1] + c[i];
            S[i] = P[i] + i;
        }

        int front = 0, tail = 0;
        deq[0] = 0;

        for(int i = 1; i <= n; ++i) {
            LL m = S[i] - L - 1;

            while(front < tail && get_slope(deq[front], deq[front+1]) < 2 * m)++front;

            dp[i] = dp[ deq[front] ] + sqr(m - S[ deq[front] ]);

            while(front < tail && get_slope(deq[tail-1], deq[tail]) >= get_slope(deq[tail], i))--tail;

            deq[++tail] = i;
        }

        printf("%lld\n", dp[n]);
    }

    return 0;
}
