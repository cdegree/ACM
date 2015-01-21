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
#include <ctime>
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

char s1[33], s2[33], pat[55];

bool eq(char *s, char *t, int st) {
    int n = strlen(s);
    for(int i = 0, j = st; i < n; ++i, ++j) {
        j %= n;
        if(s[i] != t[j]) {
            return false;
        }
    }
    return true;
}
const int K = 1000;
void pf(char *s, int st, int n) {
    for(int i = 0, j = 0; i < n; ++i, ++j) {
        j %= n;
        putchar(s[i]);
    }
    puts("");
}
int main() {
    while(~scanf("%s %s", s1, s2)) {
        int n1 = strlen(s1);
        int n2 = strlen(s2);
        srand(clock());
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < K; ++i) {
            //srand(clock());
            for(int j = 0; j < n1; ++j) {
                pat[j] = rand() % 2 + '0';
            }
            int k = 0;
            while(1) {
                if(eq(s1, pat, k % n1)) {
                    ++cnt1;
                    break;
                }
                else if(eq(s2, pat, k % n1)) {
                    ++cnt2;
                    break;
                }
                pat[k%n1] = rand() % 2 + '0';
                ++k;
                if(k>100)break;
            }
        }
        //printf("%d %d\n", cnt1, cnt2);
        double res;
        if(cnt1+cnt2==0)res=rand()%1000/1000.0;
        else  res = (double)cnt1 / (cnt2 + cnt1);
        printf("%.3f\n", res);
    }
    return 0;
}
