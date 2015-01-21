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

const int N = 110005 * 2;
int p[N];
void pk(const char *s) {
    int n = strlen(s);
    int i;
    int mx = 0;
    int id;
    for(i = 1; i < n; i++) {
        if(mx > i)
            p[i] = min(p[2*id-i],  mx - i);
        else
            p[i] = 1;
        while(s[i+p[i]] == s[i-p[i]]) ++p[i];
        if(p[i] + i > mx) {
            mx = p[i] + i;
            id = i;
        }
    }
}

void init(char *s) {
    int n = strlen(s);
    for(int i = n - 1; i >= 0; --i) {
        s[2*i+2] = s[i];
        s[2*i+3] = '#';
    }
    s[0] = '$';
    s[1] = '#';
    s[2*n+2] = '\0';
    //printf("%s\n", s);
}
char s[N];
int main() {
    //freopen("Hin.txt","r",stdin);
    while(~scanf("%s", s)) {
        init(s);
        pk(s);
        int n = strlen(s);
        int res = 0;
        for(int i = 1; i < n; ++i) {
            res = max(res, p[i]);
        }
        printf("%d\n", res - 1);
    }
    return 0;
}
