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

bool dir;
deque<int> F,M,B;

const int N = 500005;
int a[N];
char s[22];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        F.clear();
        M.clear();
        B.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        int L,R;
        scanf("%d%d",&L,&R);
        for(int i=1;i<L;++i)F.push_back(a[i]);
        for(int i=L;i<=R;++i)M.push_back(a[i]);
        for(int i=R+1;i<=n;++i)B.push_back(a[i]);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",s);

        }
    }
	return 0;
}
