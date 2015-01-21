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


int main()
{
    int n = 100000;
    freopen("1in.txt","w",stdout);
    printf("%d\n",n);
    for(int i=0;i<n;++i)printf("%d ",i%2==0?1:10000000);
    puts("");
	return 0;
}
