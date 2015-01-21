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

const int maxn = 1000005;

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
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        ExtendKmp(s, n, s, n);
        int mx = 0;
        int res = 0;
        for(int i = n / 3; i <= n - n / 3 * 2; ++i) {
            mx = max(mx, extend[i]);
        }
        int p1 = n / 3, p2 = n - n / 3 * 2;
        for(int i = n - n / 3; i < n; ++i) {
            if(extend[i] == n - i && mx >= extend[i]) {
                res = n - i;
                break;
            }
            else {
                mx = max(mx, extend[--p1]);
                mx = max(mx, extend[++p2]);
                mx = max(mx, extend[++p2]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
