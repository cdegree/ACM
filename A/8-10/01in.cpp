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
#include <ctime>
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
    freopen("01in.txt","w",stdout);
    int n=200,m=1000000,l=1,r=n;
    printf("%d %d %d %d\n",n,m,l,r);
    srand(clock());
    for(int i=0;i<m;++i)
    {
        printf("%d ",rand()%100+1);
    }
    puts("");
    puts("0 0 0 0");
	return 0;
}
