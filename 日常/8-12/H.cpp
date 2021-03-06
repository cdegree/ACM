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
    int T;
    LL X,Y;
    double P,Q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d %I64d %lf %lf",&X,&Y,&P,&Q);
        double res1 = Q*(X*P+Y*P) +X*(1-Q);
        double res2 = (1-Q)*(X*P+Y*P) +Y*Q ;
        if(res1>res2)printf("tiger");
        else printf("wolf");
        double res = max(res1,res2);
        printf(" %.4f\n",res);
    }


	return 0;
}
