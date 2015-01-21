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

const int N = 100005;
int a[N], S[N], deq[N];
double get_slope(int j, int i) {
    return (double)(S[i] - S[j]) / (i - j);
}

int main() {
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        S[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            S[i] = S[i-1] + a[i];
        }
        int front = 0, tail = -1;
        double res = -2e9;
        for(int i = k; i <= n; ++i) {

            while(front < tail && get_slope(deq[front], i) < get_slope(deq[front+1], i))++front;
            checkmax(res, get_slope(deq[front], i));
            while(front < tail && get_slope(deq[tail-1], i) < get_slope(deq[tail-1], deq[tail]))--tail;
            deq[++tail] = i;
            printf("dp = %.2f\n",res);
        }
        printf("%.2f\n", res);
    }
    return 0;
}
