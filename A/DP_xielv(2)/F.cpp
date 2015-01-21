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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

int n;
LL m;

const int N = 100015;
int a[N], deq[N] ;
LL dp[N], S[N];
multiset<LL> st;
int main() {
    while(~scanf("%d %lld", &n, &m)) {
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }

        int front = 0, tail = -1;
        int p = 1;
        dp[0] = 0;
        st.clear();
        for(int i = 1; i <= n; ++i) {
            if(a[i] > m) {
                dp[n] = -1;
                break;
            }
            sum += a[i];
            while(sum > m)sum -= a[p++];

            while(front <= tail && a[deq[tail]] < a[i]) {
                if(front < tail)
                    st.erase(dp[deq[tail-1]] + a[deq[tail]]);
                --tail;
            }
            deq[++tail] = i;
            if(front < tail)
                st.insert(dp[deq[tail-1]] + a[i]);
            while(front <= tail && deq[front] < p) {
                if(front < tail)
                    st.erase(dp[deq[front]] + a[deq[front+1]]);
                ++front;
            }
            dp[i] = dp[p-1] + a[deq[front]];
            if(front < tail && dp[i] > *st.begin()) {
                dp[i] = *st.begin();
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
