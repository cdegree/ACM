/********************

Author:Cdegree

********************/
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

int n,m,q;
bool used[5][5];


void gao(int cur)
{

}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        memset(used,0,sizeof(used));
        for(int i=0;i<q;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            used[a][b]=1;
        }

    }
	return 0;
}
