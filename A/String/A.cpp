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

const int N = 200002;
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
}
char s[N];
const int mod = 10007;
int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s", s);
        KMP(s, n, s, n);
        int res = n;
        for(int i = 0; i < n; ++i) {
            int id = p[i];
            while(~id) {
                id = p[id];
                ++res;
            }
            res%=mod;
        }
        printf("%d\n",res);




    }
    return 0;
}
