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
const int N = 100005;
int n,K;
int a[N];
vector<int> dig[N];
int len[N];
int get_len(int m)
{
    int ret=0;
    while(m>0)
    {
        ++ret;
        m/=10;
    }
    return ret;
}
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=n;++i)len[i]=get_len(a[i]);

    }
	return 0;
}
