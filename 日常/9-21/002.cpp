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

#include <ctime>

int main()
{
    freopen("02in.txt","w",stdout);
    int n=20,m=3,k=25;
    printf("%d %d %d\n",n,m,k);
    srand(clock());
    for(int i=0;i<n;++i)
    {
        printf("%d ",((i+rand())%k)+1);
    }
    puts("");
    for(int i=0;i<m;++i)
    {
        printf("%d ",((i+rand())%k)+1);
    }puts("");
	return 0;
}
