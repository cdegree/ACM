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
    freopen("Cin.txt","w",stdout);
    int n = 1000000;
    srand(clock());
    printf("%d\n",n);
    for(int i=0;i<n;++i)
    {
        printf("%d ",rand()%n );
    }
    puts("");
    int q=10000;
    printf("%d\n",q);
    for(int i=0;i<q;++i)
    {
        printf("%d\n",rand()%n+1);
    }
	return 0;
}
