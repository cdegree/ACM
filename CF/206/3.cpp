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

const int N = 300005;
int a[N];
int cnt[1000005];
int main() {
    //freopen("3.in", "r", stdin);
    int n, k;
    while(cin >> n >> k) {
        for(int i = 0; i < n; ++i)cin >> a[i];
        memset(cnt, 0, sizeof(cnt));
        sort(a, a + n);
        n = unique(a, a + n) - a;
        for(int i = 0; i < n; ++i) {
            --cnt[ a[i] + 1 ];
            ++cnt[ max(1, a[i] - k)];
        }
        for(int i = 1; i <= 1000000; ++i) {
            cnt[i] += cnt[i-1];
        }

        int res = 1;
        for(int i = 1; i <= a[0]; ++i) {
            int incnt = 0;

            for(int j = i; j <= 1000000; j += i) {
                incnt += cnt[j];
            }
            //printf("i = %d incnt=%d\n", i, incnt);
            if(incnt >= n)res = i;
        }
        printf("%d\n", res);
    }
    return 0;
}
