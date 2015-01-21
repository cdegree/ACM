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

const int N = 1000006;
int a[N];
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    int n;
    while(cin >> n) {
        int cnt[5] = {0};
        for(int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a,a+n,cmp);

        printf("%d\n", res);
    }
    return 0;
}
