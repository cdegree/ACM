/********************

Author:Cdegree

********************/
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

LL a[4], b[4];

int main() {
    while(1) {
        bool all = 1;
        for(int i = 0; i < 4; ++i) {scanf("%lld", a + i); if(a[i])all = 0; }
        if(all)break;
        int cnt = 0;
        while(1) {
            ++cnt;
            all = 1;
            for(int i = 0; i < 4; ++i) {
                b[i] = abs(a[i] - a[(i+1)%4]);
            }
            for(int i = 0; i < 4; ++i) {a[i] = b[i]; if(a[i])all = 0;  }
            if(all)break;
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}
