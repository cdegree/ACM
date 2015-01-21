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


const int N = 3000;

bool contain38(int n) {
    bool b1 = 0, b2 = 0;
    while(n > 0) {
        if(n % 10 == 3)b1 = 1;
        if(n % 10 == 8)b2 = 1;
        n /= 10;
    }
    return b1 && b2;
}

int main() {
    int sum = 0;
    for(int i = 1; i < N; ++i) {
        if(contain38(i)) {
            sum += i;
            //printf("%d\n",i);
        }
    }
    printf("%d\n", sum);
    return 0;
}
