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
    double l,k,h;
    while(~scanf("%lf%lf%lf",&l,&k,&h))
    {
        double res=h;
        while(res*k<l)++res;
        printf("%.6f %.6f\n",res,res);
    }
	return 0;
}
