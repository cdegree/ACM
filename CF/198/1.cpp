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
typedef unsigned long long uLL;
#pragma comment(linker,"/STACK:102400000,102400000")
const int N = 100005;
LL a[N];

int main()
{
    LL n;
    //freopen("1in.txt","r",stdin);
    while(cin>>n)
    {
        LL sum = 0 ;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        for(LL i=1;i<n;++i)
        {
            sum += 2LL*abs(a[i]-a[i-1])*i*(n-i);
        }
        LL gcd = __gcd(sum,n);
        sum/=gcd,n/=gcd;
        cout<<sum<<" "<<n<<endl;
    }
	return 0;
}
