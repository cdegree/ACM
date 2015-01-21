#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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

int n;
const int N = 20005;
LL A[N], B[N], C[N];
bool judge(LL m) {
    LL sum = 0;
    for(int i = 0; i < n; ++i) {
        if(A[i] <= m) {
            LL K = min(m, B[i]);
            sum += (K - A[i]) / C[i] + 1;
        }
    }
    return sum & 1;
}
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%I64d %I64d %I64d", A + i, B + i, C + i);
        }
        LL l = 1, r = 1LL << 32, ans = -1, mid;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(judge(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(~ans) {
            LL sum = 0;
            for(int i = 0; i < n; ++i) {
                if(ans >= A[i] && ans <= B[i] && (ans - A[i]) % C[i] == 0)++sum;
            }
            printf("%I64d %I64d\n", ans, sum);
        }
        else {
            puts("DC Qiang is unhappy.");
        }
    }
    return 0;
}
