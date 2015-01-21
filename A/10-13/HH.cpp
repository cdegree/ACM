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


#include <ctime>
int main() {
    freopen("Hin.txt", "w", stdout);
    srand(clock());
    for(int c = 0; c < 20; ++c) {
        int n = 300000;
        printf("%d\n", n);
        for(int i = 0; i < n; ++i) {
            printf("%c", rand() % 26 + (i&1)?'a':'A' );
        }
        puts("");
    }
    return 0;
}
