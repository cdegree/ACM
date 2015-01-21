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


int n;
int a[1004];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)cin>>a[i];
        int mx=0,id=0;
        for(int i=1;i<n-1;++i)
        {
            if(a[i-1]+a[i]+a[i+1]>mx)
            {
                mx=a[i-1]+a[i]+a[i+1];
                id=i+1;
            }
        }
        printf("%d %d\n",mx,id);
    }

	return 0;
}
