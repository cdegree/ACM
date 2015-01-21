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
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

int a[55];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;++i)cin>>a[i];
        sort(a+1,a+m+1);
        int res=1e8;
        for(int i=1;i+n<=m+1;++i)
        {
            res=min(res,a[i+n-1]-a[i]);
        }
        cout<<res<<endl;
    }
	return 0;
}
