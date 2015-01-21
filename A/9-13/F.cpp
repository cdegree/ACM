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



map<int, int> Fuck;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        Fuck.clear();
        int a;
        for(int i = n; i >= 1; --i) {
            scanf("%d",& a);
            Fuck[ a ]++;
        }
        bool ok=1;
        for(map<int,int>::iterator it =Fuck.begin();it!=Fuck.end();++it )
        {
            if(it->second&1)ok=0;
        }
        printf("%d\n", ok);
    }
    return 0;
}
