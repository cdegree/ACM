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



int main() {
    freopen("2in.txt", "w", stdout);
    int n = 50;
    for(int i = 0; i < n; ++i) {
        printf("%lld%c", ((LL)rand()*rand()*rand() + rand()*rand()+rand()), (i == n - 1) ? '\n' : ',');
    }
    printf("%lld\n", ((LL)rand()*rand()*rand() + rand()*rand()+rand()));
    return 0;
}
