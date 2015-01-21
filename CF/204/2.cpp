/********************Cdegree********************/
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

double gao(int i)
{
    if(i>100)return 0;
    return 0.5*(i+1+gao(i+2));
}
int a[3003];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)cin>>a[i];
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            for(int j=n-1;j>i;--j)
            {
                if(a[j-1]>a[j])
                {
                    ++cnt;
                    swap(a[j-1],a[j]);
                }
            }
        }
        n=cnt;
        double res = n/2*4+(n&1);
        printf("%.6f\n",res);
    }
	return 0;
}
