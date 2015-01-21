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
int a[N], deqmx[N], deqmn[N];

int main() {
    int n, down, up;
    while(~scanf("%d%d%d", &n, &down, &up)) {
        for(int i = 1; i <= n; ++i)scanf("%d", a + i);
        int f1 = 0, t1 = -1, f2 = 0, t2 = -1;
        int res = 0, pre = 0;
        for(int i = 1; i <= n; ++i) {
            while(f1 <= t1 && a[i] > a[ deqmx[t1] ])--t1; deqmx[++t1] = i;
            while(f2 <= t2 && a[i] < a[ deqmn[t2] ])--t2; deqmn[++t2] = i;
            while(a[ deqmx[f1] ] - a[ deqmn[f2] ] > up) {
                if(f1 <= t1 && deqmx[f1] < deqmn[f2]) {pre = deqmx[f1++]; }
                else {pre = deqmn[f2++];}
            }
            if(a[ deqmx[f1] ] - a[ deqmn[f2] ] >= down) {
                checkmax(res, i - pre);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
