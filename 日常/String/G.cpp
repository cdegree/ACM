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

const int N = 300010;
int next[N], extend[N];
void ExtendKmp(char s[], int ls, char t[], int lt) {
    int i, j, k;
    int Len, L;
    j = 0;
    while(t[j+1] == t[j] && j + 1 < lt) j++;
    next[1] = j, k = 1;
    for(i = 2; i < lt; i++) {
        Len = k + next[k], L = next[i-k];
        if(Len > L + i) next[i] = L;
        else {
            j = Len - i > 0 ? Len - i : 0;
            while(t[i+j] == t[j] && i + j < lt) j++;
            next[i] = j, k = i;
        }
    }
    j = 0;
    while(s[j] == t[j] && j < lt && j < ls) j++;
    extend[0] = j, k = 0;
    for(i = 1; i < ls; i++) {
        Len = k + extend[k], L = next[i-k];
        if(Len > L + i) extend[i] = L;
        else {
            j = Len - i > 0 ? Len - i : 0;
            while(s[i+j] == t[j] && i + j < ls && j < lt) j++;
            extend[i] = j, k = i;
        }
    }
}
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
char s[N], s2[N];
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%s", s);
        int m = strlen(s);
        strcpy(s2, s);
        strcat(s, s2);
        int n = m * 2;
        ExtendKmp(s, n, s, m);
        KMP(s, m, s, m);
        int len = p[m-1] + 1;
        int cnt = m - 1 - p[m-1];
        int div = 1;
        if(cnt < m && m % cnt == 0) {
            div = m / cnt;
        }
        /*
        for(int i = 0; i < m; ++i) {
            printf("%3c", s[i]);
        } puts("");
        for(int i = 0; i < m; ++i) {
            printf("%3d", p[i]);
        } puts("");
        for(int i = 0; i < m; ++i) {
            printf("%3d", next[i]);
        } puts("");
        for(int i = 0; i < m; ++i) {
            printf("%3d", extend[i]);
        } puts("");
        */
        int L = 0, E = 0, G = 0;
        for(int i = 0; i < m; ++i) {
            if(extend[i] >= m) {
                ++E;
            }
            else if(s[i + extend[i] ] > s[ extend[i] ]) {
                ++G;
            }
            else {
                ++L;
            }
        }
        printf("Case %d: %d %d %d\n", t, L/div, E/div, G/div);
    }
    return 0;
}
