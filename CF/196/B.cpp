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

LL a,b,c,d;
int main()
{
    while(cin>>a>>b>>c>>d)
    {
        LL lcm1 = a*c/__gcd(a,c);
        LL lcm2 = b*d/__gcd(b,d);
        LL p,q;
        if(b*(lcm1/a)<=d*(lcm1/c))
        {
            q = lcm1*d*(lcm1/c);
            p = lcm1*(d*(lcm1/c) - b*(lcm1/a));
        }
        else
        {
            q = lcm2*c*(lcm2/d);
            p = lcm2*(c*(lcm2/d) - a*(lcm2/b));
        }
        LL gcd=__gcd(q,p);
        p/=gcd,q/=gcd;
        cout<<p<<"/"<<q<<endl;
    }
	return 0;
}
