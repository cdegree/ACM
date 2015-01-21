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
map<string, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

char s[9];
const int N = 5005;
string dig[N];
map<string, int> mp;
int mpc[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

string dictodig(char *s) {
    int n = strlen(s);
    string ret = "";
    for(int i = 0; i < n; ++i) {
        ret += mpc[ s[i] - 'a' ] + '0';
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    int n, m;
    while(T--) {
        mp.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            dig[i] = s;
        }
        for(int j = 0; j < m; ++j) {
            scanf("%s", s);
            mp[dictodig(s)]++;
        }
        for(int i = 0; i < n; ++i) {
            printf("%d\n", mp[ dig[i] ]);
        }
    }
    return 0;
}
