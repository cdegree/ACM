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


char s[105], t[105];
string s1, s2;
int main() {
    int T;
    scanf("%d", &T);
    for(int ct = 1; ct <= T; ++ct) {
        scanf("%s%s", s, t);
        s1 = s;
        s2 = t;
        int cnt_s1 = 0, cnt_s2 = 0;
        int n = s1.size();
        for(int i = 0; i < n; ++i) {
            if(s1[i] == '1')++cnt_s1;
            if(s2[i] == '1')++cnt_s2;
        }
        printf("Case %d: ", ct);
        if(cnt_s1 > cnt_s2) {
            puts("-1");
            continue;
        }
        int cha = cnt_s2 - cnt_s1;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(cha > 0 && s1[i] == '?' && s2[i] == '1') {
                --cha;
                ++res;
                s1[i] = '1';
            }
        }
        if(cha > 0) { //问号不够用

            for(int i = 0; i < n; ++i) {
                if(cha > 0 && s1[i] == '?') {
                    --cha;
                    ++res;
                    s1[i] = '1';
                }
            }
            if(cha > 0) { //问号不够用
                for(int i = 0; i < n; ++i) {
                    if(s1[i] == '0' && s2[i] == '1' && cha > 0) {
                        --cha;
                        ++res;
                        s1[i] = '1';
                    }
                }
                for(int i = 0; i < n; ++i) {
                    if(s1[i] == '0' && cha > 0) {
                        --cha;
                        ++res;
                        s1[i] = '1';
                    }
                }
                int ccnt = 0;
                for(int i = 0; i < n; ++i) {
                    if(s1[i] != s2[i]) {
                        ++ccnt;
                    }
                }
                res += ccnt / 2;
            }
            else {
                for(int i = 0; i < n; ++i) {
                    if(s1[i] == '?') {
                        s1[i] = '0';
                        ++res;
                    }
                }
                int ccnt = 0;
                for(int i = 0; i < n; ++i) {
                    if(s1[i] != s2[i]) {
                        ++ccnt;
                    }
                }
                res += ccnt / 2;
            }
        }
        else {
            for(int i = 0; i < n; ++i) {
                if(s1[i] == '?') {
                    s1[i] = '0';
                    ++res;
                }
            }
            int ccnt = 0;
            for(int i = 0; i < n; ++i) {
                if(s1[i] != s2[i]) {
                    ++ccnt;
                }
            }
            res += ccnt / 2;
        }
        printf("%d\n", res);
    }
    return 0;
}
