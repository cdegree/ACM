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
int b[N];
int cnt[26], sub[26];
int sb[N][26];

int p[N];
int KMP(int *a, int n, int *b, int m) {
    p[0] = -1;
    int i, j = -1;
    for(i = 1; i <= m; i++) {
        while((j > -1) && (b[j+1] != b[i]))
            j = p[j];
        if(b[j+1] == b[i]) j++;
        p[i] = j;
    }
    //for(i=0;i<m;i++) printf("%d   ",p[i]); printf("\n");
    j = -1;
    for(i = 0; i < n; i++) {
        while((j > -1) && (b[j+1] != a[i] - sb[ i+m-j-1 ][ a[i] ])) j = p[j];
        if(b[j+1] == a[i] - sb[ i+m-j-1 ][ a[i] ]) {
            j++;
        }
        if(j == m - 1) {
            printf("i = %d\n", i);
            //return i - m + 1;
            j = p[j];
        }
    }
    printf("fuck\n");
    return -1;
}
int change[N];

int main() {
    int n, m, k;
    freopen("02in.txt", "r", stdin);
    while(~scanf("%d%d%d", &n, &m, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < m; ++i) {
            scanf("%d", b + i);
            ++cnt[ b[i] ];
        }
        memset(sub, 0, sizeof(sub));
        memset(change, 0, sizeof(change));
        for(int i = 1; i <= k; ++i) {
            if(cnt[i] == 0) {
                ++sub[i];
            }
            sub[i] += sub[i-1];
        }

        for(int i = 0; i < m; ++i) {
            b[i] -= sub[ b[i] ];
            printf("%d ", b[i]);
        } puts("");

        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < m; ++i) {
            ++cnt[ a[i] ];
        }
        memset(sb, 0, sizeof(sb));
        for(int i = m; i < n; ++i) {
            for(int j = 1; j <= k; ++j) {
                if(cnt[j] == 0) {
                    ++sb[i][j];
                }
                sb[i][j] += sb[i][j-1];
                if(sb[i][j] != sb[i-1][j]) {
                    change[i] = 1;
                }
            }
            --cnt[ a[i-m] ];
            ++cnt[ a[i] ];
        }
        for(int i = m; i < n; ++i) {
            for(int j = 1; j <= k; ++j) {
                printf("%d ", sb[i][j]);
            } puts("");
        }
        for(int i = m; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%d ", a[i-m+j] - sb[i][ a[i-m+j] ]);
            } puts("");
        }
        KMP(a, n, b, m);
        int res = 0;
        printf("%d\n", res);
    }
    return 0;
}
