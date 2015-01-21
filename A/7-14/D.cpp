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
using namespace std;

typedef long long LL ;

long double x,y,r;
long double pi = acos(-1.0);
int main()
{
    while(cin>>x>>y>>r)
    {
        //+r*(log(r*r)-1)/2
        double res = r*acos(-1.0)*log(x*x+y*y)*r;
        printf("%.15f\n",res);
    }
	return 0;
}
