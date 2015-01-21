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
#include <ctime>
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

int a[555][555];
int main()
{
    freopen("Bin.txt","w",stdout);
    int n=500;
    printf("%d\n",n);
    srand(clock());
    memset(a,0,sizeof(a));
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            a[i][j]=a[j][i]=rand();
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%d ",a[i][j]);
        }
        puts("");
    }
    puts("");
	return 0;
}
