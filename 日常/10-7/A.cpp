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


char s[202];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        int res = 300;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 5; j < n; ++j) {
                bool ok1 = 0, ok2 = 0, ok3 = 0;
                for(int k = i; k <= j; ++k) {
                    if(isdigit(s[k])) {
                        ok1 = 1;
                    }
                    else if(islower(s[k])) {
                        ok2 = 1;
                    }
                    else if(isupper(s[k])) {
                        ok3 = 1;
                    }
                }
                if(ok1 && ok2 && ok3) {
                    checkmin(res, j - i + 1);
                }
            }
        }
        printf("%d\n",res==300?0:res);
    }
    return 0;
}
