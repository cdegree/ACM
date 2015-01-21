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

char str[105];
string s;
string pa = "desu";
string pt = "nanodesu";
int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%s", str);
        s = str;
        int n = strlen(str);
        if(n >= 4 && s.substr(n - 4, 4) == pa) {
            s.erase(n - 4, 4);
            s += pt;
        }
        else {
            s += pt;
        }
        printf("Case #%d: %s\n", t, s.c_str());
    }
    return 0;
}
