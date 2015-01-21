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
struct Floor {
    LL w, s;
} F[N];


bool cmp(Floor a, Floor b) {
    return a.w - b.s < b.w - a.s;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%I64d %I64d", &F[i].w, &F[i].s);
        }
        sort(F, F + n, cmp);
        LL S = 0;
        LL mx = 0;
        for(int i = 0; i < n; ++i) {
            checkmax(mx, S - F[i].s);
            S += F[i].w;
        }
        printf("%I64d\n", mx);
    }
    return 0;
}
