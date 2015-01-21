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

string tmp[] = {
    "",
    "a",
    "ab",
    "aab",
    "aabb",
    "aaaba",
    "aaabab",
    "aaababb",
    "aaababbb",
    "aaaababba",
    "aaaababbaa",
    "aaaababbaaa",
    "aaaababbaaaa",
    "aaaababbaabab",
    "aaaababbaababb",
    "aaaababbaababba",
    "aaaababbaababbaa",
    "aaaababbaababbaaa",
    "aaaababbaababbaaaa"
};
string mod = "babbaa";
int main() {
    int T, m, n;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &m, &n);
        printf("Case #%d: ", t);
        if(m == 1) {
            for(int j = 0; j < n; ++j) {
                printf("%c", 'a');
            } puts("");
        }
        else if(m == 2) {
            if(n < 13) {
                printf("%s\n", tmp[n].c_str());
            }
            else {
                string ans = "aaaa";
                int p = 4;
                while(p + 6 <= n) {
                    ans += mod;
                    p += 6;
                }
                p = n - p;
                if(p <= 2) {
                    while(p > 0) {
                        --p;
                        ans += "a";
                    }
                }
                else {
                    for(int j = 0; j < p; ++j) {
                        ans += mod[j];
                    }
                }
                printf("%s\n", ans.c_str());
            }
        }
        else if(m >= 3) {
            int j = 0;
            for(int i = 0; i < n; ++i) {
                printf("%c", j + 'a');
                j = (j + 1) % 3;
            }
            puts("");
        }
    }
    return 0;
}
