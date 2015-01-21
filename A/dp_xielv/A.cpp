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
int a[N];
int sum[N];
inline LL get_up(int j, int i) {
    return sum[i] - sum[j];
}
inline LL get_down(int j, int i) {
    return i - j;
}
int q[N];
int n, k;
int input() {
    char c = ' ';
    while(c > '9' || c < '0')c = getchar();
    int ret = 0;
    while(c <= '9' && c >= '0') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}

int main() {
    //freopen("Ain.txt","r",stdin);
    int cnt = 0;
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 1; i <= n; ++i) {
            //a[i] = input();
            scanf("%d", a + i);
        }
        sum[0] = 0;
        for(int i = 1; i <= n; ++i)sum[i] = sum[i-1] + a[i];
        int front = 0, tail = 0;
        q[0] = 0;
        double res = 0;
        for(int i = k; i <= n; ++i) {
            while(front < tail && get_up(q[front], i)*get_down(q[front+1], i) <= get_up(q[front+1], i)*get_down(q[front], i))++front;
            checkmax(res, (double)get_up(q[front], i) / get_down(q[front], i));
            int j = i - k + 1;
            while(front < tail && get_up(q[tail], j)*get_down(q[tail-1], q[tail]) <= get_up(q[tail-1], q[tail])*get_down(q[tail], j))--tail;
            q[++tail] = j;
        }
        printf("%.2f\n", res);
    }
    return 0;
}
