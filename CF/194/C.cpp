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


LL e3[60];
int main()
{
    LL n;
    e3[0]=1;
    for(int i=1;e3[i-1]*3<=1000000000000000000LL;++i)
    {
        e3[i]=e3[i-1]*3LL;
    }
    while(cin>>n)
    {
        for(int i=0;;++i)
        {
            LL rm=n%e3[i];
            if(rm!=0)
            {
                cout<<(n+e3[i]-1)/e3[i]<<endl;
                break;
            }
        }
    }
	return 0;
}
