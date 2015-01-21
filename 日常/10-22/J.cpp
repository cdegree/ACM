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

const int N = 20002;

LL A[N], B[N], C[N];
int n;
LL judge(LL mid) {
    LL sum = 0;
    for(int i = 0; i < n; ++i) {
        if(A[i] > mid)continue;
        if(A[i] <= mid && mid <= B[i]) {
            sum += (mid - A[i]) / C[i] + 1;
        }
        else {
            sum += (B[i] - A[i]) / C[i] + 1;
        }
    }
    //printf("mid = %I64d , sum  =%I64d\n", mid, sum);
    return sum;
}
int main() {

    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%I64d %I64d %I64d", A + i, B + i, C + i);
        }
        LL l = 0, r = 1e12, mid, ans = -1;
        while(l <= r) {
            mid = (l + r) / 2;
            if(judge(mid) & 1) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(ans == -1) {
            puts("DC Qiang is unhappy.");
        }
        else {
            int sum = 0;
            for(int i = 0; i < n; ++i) {
                if(A[i] <= ans && ans <= B[i] && (ans - A[i]) % C[i] == 0) {
                    ++sum;
                }
            }
            printf("%I64d %d\n", ans, sum);
        }
    }
    return 0;
}
