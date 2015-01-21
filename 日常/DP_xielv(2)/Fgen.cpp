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



int main()
{
    freopen("Fin.txt","w",stdout);
    int n=10;
    LL m=10000000LL;
    printf("%d %lld\n",n,m);
    for(int i=1;i<=n;++i)
    {
        int r =rand();
        printf("%d ",r);
    }
    puts("");
	return 0;
}
