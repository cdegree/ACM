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

const int N = 1005;
LL C[N][N];
const LL mod = 1e9+7;
void init()
{
    for(int i=0;i<N;++i)
    {
        C[i][i]=C[i][0]=1;
    }
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<i;++j)
        {
            C[i][j] = C[i-1][j-1] +C[i-1][j];
            C[i][j] %= mod;
        }
    }
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<N;++j)
        {
            S2[i][j] =
        }
    }
}
LL S2[N][N];

int main()
{
    LL n,r,k,m;
    init();
    while(cin>>n>>r>>k>>m)
    {
        LL p = n - (r-1)*(k-1);

    }
	return 0;
}
