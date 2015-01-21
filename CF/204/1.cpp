/********************Cdegree********************/
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
const int N = 4002;
LL a[N];
int b;
bool used[N];

bool cmp(LL a,LL b)
{
    return a<b;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < 2 * n; ++i) {
            scanf("%d.%I64d", &b, a + i);
        }
        sort(a, a + 2 * n,cmp);
        memset(used, 0, sizeof(used));
        LL sum = 0;
        for(int i=0;i<2*n;++i)
        {
            if(used[i])continue;
            int mn = 1e8;
            int id;
            for(int j=i+1;j<2*n;++j)
            {
                if( !used[j]&& abs(sum - a[i] + (1000- a[j])%1000) < mn  )
                {
                    id=j;
                    mn = abs(sum - a[i] + (1000- a[j])%1000);
                }
            }
            used[id]=1;
            sum = sum - a[i] + (1000- a[id])%1000;
        }
        sum=abs(sum);

        printf("%I64d.%03I64d\n", sum / 1000, sum % 1000);
    }
    return 0;
}
