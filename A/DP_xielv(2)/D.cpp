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

const int N = 2002;
int dp[N][N], AP[N], BP[N], AS[N], BS[N], deq[N];
int T, t, maxp, w;
const int inf = 2e9;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &t, &maxp, &w);
        for(int i = 1; i <= t; ++i) {
            scanf("%d%d%d%d", AP + i, BP + i, AS + i, BS + i);
        }
        for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)dp[i][j] = -inf;
        for(int i = 1; i <= w + 1; ++i) {
            dp[i][0] = 0;
            for(int j = 1; j <= AS[i]; ++j) {
                dp[i][j] = -AP[i] * j;
            }
        }
        for(int i = 1; i <= w + 1; ++i) {
            for(int j = 0; j <= maxp; ++j) {
                checkmax(dp[i][j], dp[i-1][j]);
            }
        }
        for(int i = w + 2; i <= t; ++i) {
            int pre = i - w - 1;
            int front = 0, tail = -1, k;
            for(int j = 0; j <= maxp; ++j) {
                checkmax(dp[i][j], dp[i-1][j]);
                int tmp = dp[pre][j] + j * AP[i];
                while(front <= tail && tmp > dp[pre][ deq[tail] ] + deq[tail] * AP[i])--tail;
                deq[++tail] = j;
                k = deq[front];
                while(j - k > AS[i])k = deq[++front];
                checkmax(dp[i][j], dp[pre][ k ] + k * AP[i] - j * AP[i]);
            }
            front = 0, tail = -1;
            for(int j = maxp; j >= 0; --j) {
                int tmp = dp[pre][j] + j * BP[i];
                while(front <= tail && tmp > dp[pre][ deq[tail] ] + deq[tail] * BP[i])--tail;
                deq[++tail] = j;
                k = deq[front];
                while(k - j > BS[i])k = deq[++front];
                checkmax(dp[i][j], dp[pre][ k ] + k * BP[i] - j * BP[i]);
            }
        }
        printf("%d\n", dp[t][0]);
    }
    return 0;
}
