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

const int N = 200005;
int S[N], a[N];

int deq[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)scanf("%d", a + i);
        for(int i = n + 1; i < 2 * n; ++i) {
            a[i] = a[i-n];
        }
        S[0] = 0;
        for(int i = 1; i < 2 * n; ++i) {
            S[i] = S[i-1] + a[i];
        }
        int front = 0, tail = -1;
        int res = -2e9 - 1, st = 0, ed = 0;
        for(int i = 1; i < 2 * n; ++i) {
            while(front <= tail && S[ deq[tail] ] > S[i])--tail;
            deq[++tail] = i - 1;
            if(i - deq[front] > k)++front;
            LL tmp = S[i] - S[ deq[front] ];
            if(res < tmp || (res == tmp && (st > deq[front]  || (st == deq[front] + 1  && ed - st > i - deq[front])))) {
                res = S[i] - S[ deq[front] ];
                st = deq[front] + 1 ;
                ed = i;
            }
        }
        if(st > n)st -= n;
        if(ed > n)ed -= n;
        printf("%d %d %d\n", res, st, ed);
    }
    return 0;
}
