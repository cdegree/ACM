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
int p[N];
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
    for(i = 0; i < n; i++) {
        while((j > -1) && (b[j+1] != a[i])) j = p[j];
        if(b[j+1] == a[i]) {
            j++;
        }
        if(j == m - 1) {
            //printf("i=%d\n",i);
            //return i-m+1;
            j = p[j];
        }
    }
    return -1;
}
char s[N], t[N];

int main() {
    while(~scanf("%s%s", s, t)) {
        int m = min(strlen(s),strlen(t));
        strcat(s,t);
        int n = strlen(s);
        KMP(s, n, s, n);
        int res = min(p[n-1]+1,m);

        if(res) {
            for(int i = 0; i <  res; ++i) {
                printf("%c", s[i]);
            }
            printf(" %d\n",res);
        }
        else {
            puts("0");
        }
    }
    return 0;
}
