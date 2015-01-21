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

LL res;
void gao(vector<int> ball, int a, int b) {
    if(a < b)return ;
    if(ball.size() == 0) {
        ++res;
    }
    for(int i = 0; i < ball.size(); ++i) {
        vector<int> rb = ball;
        rb.erase(rb.begin() + i);
        gao(rb, max(a, ball[i]), b);
        gao(rb, a, max(b, ball[i]));
    }
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        res = 0;
        vector<int> vi;
        LL m = (1LL << n);
        for(int i = 1; i <= n; ++i) {
            m *= i;
            vi.push_back(i);
        }
        gao(vi, 0, 0);
        //cout<<m<<endl;
        LL g = __gcd(res, m);
        g=1;
        printf("%lld/%lld\n", res / g, m / g);
    }
    return 0;
}
