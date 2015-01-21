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


LL a[111];
int main() {
    int n;
    while(cin >> n) {
        LL mx = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            checkmax(mx, a[i]);
        }
        LL g = __gcd(a[0], a[1]);
        for(int i = 2; i < n; ++i) {
            g = __gcd(g, a[i]);
        }
        LL cnt = mx / g;
        cnt -= n;
        if(cnt & 1) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
