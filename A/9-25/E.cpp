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



int main()
{
    int a,b,c,a1,b1,c1;
    int n;


    printf("%.6f\n",0.0274*2500+27.4*2.4+51*2.74);
    for(int i=0;i<10;++i)
    {
        printf("%d\n",(i+4)*5*6 );
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d.%d %d.%d %d.%d",&a,&a1,&b,&b1,&c,&c1);
        a = a*100+a1;
        b = b*100+b1;
        c = c*100+c1;
        int g = __gcd(a,b);
        g = __gcd(g,c);
        int P = a*b*c;
        P /= g;
        if(P/a+P/b+P/c>a+b+c)
        {
            puts("Aha");
        }
        else
        {
            puts("No way");
        }
    }
	return 0;
}
