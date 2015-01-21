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

const int N = 500005;
LL dp[N], a[N], S[N], deq[N];

LL get_up(int j, int k) {
    return dp[j] + sqr(S[j]) - dp[k] - sqr(S[k]);
}
LL get_down(int j, int k) {
    return S[j] - S[k];
}
int main() {
    LL n, m;
    while(~scanf("%I64d%I64d", &n, &m)) {
        S[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            S[i] = S[i-1] + a[i];
        }
        int front = 0, tail = 0;
        deq[0] = 0;
        for(int i = 1; i <= n; ++i) {
            while(front < tail && get_up(deq[front+1], deq[front]) < 2 * S[i]*get_down(deq[front+1], deq[front]))++front;
            int j = deq[front];
            dp[i] = dp[j] + sqr(S[i] - S[j]) + m;
            while(front < tail && get_up(deq[tail-1], deq[tail])*get_down(deq[tail], i) >= get_up(deq[tail], i)*get_down(deq[tail-1], deq[tail]))--tail;
            deq[++tail] = i;
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
