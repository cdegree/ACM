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
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int maxn = 1000005;

/*
   理解扩展KMP 求一个串的所有后缀与模式串的最长公共前缀
   一个例子 (a a c a d e f g a a c a) *2
   extend   24 1 0 1 0 0 0 0 4 1 0 2
   extend[8]=4; 算extend[9],先从i开始最多能有多少重合的,再与extend[i-k]比较
*/
int next[maxn], extend[maxn];
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
char s[maxn];

int main() {
    int T;
    //freopen("5in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        ExtendKmp(s, n, s, n);

        int res  = 0;

        int mx = 0;
        for(int i = n / 3; i <= n - 2 *(n / 3); ++i) {
            mx = max(mx, extend[i]);
        }
        //printf("mx = %d\n",mx);
        for(int len = n / 3; len >= 0; --len) {
            if(extend[n-len] >= len && mx >= len) {
                res = len;
                break;
            }
            else {
                mx = max(mx, max(extend[len-1], max(extend[n-2*(len-1)-1], extend[n-2*(len-1)])));
            }
        }
        printf("%d\n", res);
        /*
        for(int i = 0; i < n; ++i) {
            printf("%3c", s[i]);
        } puts("");
        for(int i = 0; i < n; ++i) {
            printf("%3d", extend[i]);
        } puts("");*/
    }
    return 0;
}
