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

int dp[2][N], S[N], SP[N], v[N], deq[N];

int n, m;

int t1, t2;
const int inf = 1e9;
double get_slope(int j, int k) {
    return (double)(2 * dp[t1][j] + sqr(S[j]) + SP[j] - 2 * dp[t1][k] - sqr(S[k]) - SP[k]) / (S[j] - S[k]);
}

//int cost(int j, int i) {return (sqr(S[i] - S[j]) - (SP[i] - SP[j])) / 2;}

int main() {
    while(~scanf("%d%d", &n, &m), n || m) {
        S[0] = SP[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", v + i);
            S[i] = S[i-1] + v[i];
            SP[i] = SP[i-1] + sqr(v[i]);
        }
        dp[0][0] = 0;
        for(int i = 1; i < N; ++i)dp[0][i] = inf;
        t1 = 1, t2 = 0;
        for(int j = 1; j <= m + 1; ++j) {
            int front = 0, tail = 0;
            deq[0] = 0;
            t1 ^= 1, t2 ^= 1;
            for(int i = 1; i <= n; ++i) {

                while(front < tail && get_slope(deq[front+1], deq[front]) < 2 * S[i])++front;
                dp[t2][i] = dp[t1][ deq[front] ] + (sqr(S[i] - S[ deq[front] ]) - SP[i] + SP[ deq[front] ])/2;
                while(front < tail && get_slope(deq[tail-1], deq[tail]) >= get_slope(deq[tail], i))--tail;

                deq[++tail] = i;



            }
        }
        printf("%d\n", dp[t2][n]);
    }
    return 0;
}
