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

const int N = 1000005;
int mx[N], mn[N], a[N];
int deq[N];

int main() {
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 1; i <= n; ++i)scanf("%d", a + i);
        int front = 0, tail = -1;
        for(int i = 1; i <= n; ++i) {
            while(front <= tail && a[deq[tail]] > a[i])--tail;
            deq[++tail] = i;
            if(i - k >= deq[front])++front;
            if(i >= k) {
                mn[i-k] = a[deq[front]];
            }
        }
        front = 0, tail = -1;
        for(int i = 1; i <= n; ++i) {
            while(front <= tail && a[deq[tail]] < a[i])--tail;
            deq[++tail] = i;
            if(i - k >= deq[front])++front;
            if(i >= k) {
                mx[i-k] = a[deq[front]];
            }
        }
        for(int i = 0; i <= n - k; ++i) {
            printf("%d%c", mn[i], i == n - k ? '\n' : ' ');
        }
        for(int i = 0; i <= n - k; ++i) {
            printf("%d%c", mx[i], i == n - k ? '\n' : ' ');
        }
    }
    return 0;
}
