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
int p[maxn];
int mx;
int KMP(char *a, int n, char *b, int m) {
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
    bool OK = 0;
    int st = 0;
    for(i = 0; i < n; i++) {
        while((j > -1) && (b[j+1] != a[i])) j = p[j];
        if(b[j+1] == a[i]) {
            j++;
        }
        int H = j+1;
        mx = max(mx,min(min(i, H), (n - i) / 2));
        if(j == m - 1) {
            //printf("i=%d\n",i);
            if(i - m + 1 >= m && !st) {
                st = i;
            }
            if(st && i - m + 1 > st&& i==n-1) {
                OK = 1;
            }
            //return i-m+1;
            j = p[j];
        }
    }
    return OK;
}
char s[N];
int main() {
    int T;
    //freopen("5in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        int ans=0;
        mx=0;
        KMP(s,n,s,n);
        //for(int i = 1; i <= n; ++i) {printf("sa[%d]=%d %s\n", i, sa[i], &s[ sa[i] ]);}
        for(int len = n / 3; len >= 1; --len) {
            //printf("rank[%d]=%d rank[%d]=%d\n",0,rank[0],n-len,rank[n-len]);
            //printf("len = %d H = %d\n",len ,H);
            if(KMP(s, n, s, len)) {
                ans = len;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
