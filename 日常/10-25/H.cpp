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


int a[1005];
struct bomb {
    int val;
    int cnt;
} B[1005];
int main() {
    int n;
    LL p;
    while(~scanf("%d%I64d", &n, &p)) {
        a[0] = 0;
        for(int i = 1; i <= n; ++i)scanf("%d", a + i);
        sort(a, a + n + 1);
        int m = 0;
        B[0].val = a[1];
        B[0].cnt = 1;
        for(int i = 2; i <= n; ++i) {
            if(a[i] == a[i-1]) {
                B[m].cnt++;
            }
            else {
                B[++m].val = a[i];
                B[m].cnt = 1;
            }
        }
        bool gao = 1;
        int chishu = 0, res = 0;
        while(gao) {
            gao = 0;
            int sum = 0, cnt = 0, pos = -1;
            for(int i = 0; i <= m; ++i) {
                if(!B[i].cnt)continue;
                if(B[i].val*(B[i].cnt + cnt) <= p) {
                    cnt += B[i].cnt;
                    pos = i;
                    gao = 1;
                }
                else break;
            }
            if(gao) {
                ++chishu;
                for(int i = 0; i <= pos; ++i) {
                    B[i].cnt = 0;
                    B[i].val = 0;
                }
                res += cnt;
            }
        }
        printf("%d %d\n", res, chishu);

    }
    return 0;
}
