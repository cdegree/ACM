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
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            int a;
            cin>>a;
            sum+=a*a;
        }
        cout<<sum<<endl;
    }
	return 0;
}
