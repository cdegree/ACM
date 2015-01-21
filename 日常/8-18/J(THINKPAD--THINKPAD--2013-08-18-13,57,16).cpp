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

LL res[100005];
int main()
{
    LL n,h;
    while(~scanf("%I64%I64d",&n,&h))
    {
        ++h;
        int len=0;
        if(h*h>n)
        {
            puts("0");
            continue;
        }
        LL cur=h*h;
        LL l=cur+h;
        LL add = 2*h+1;
        printf("cur = %lld l = %lld,add = %lld\n",cur,l,add);
        return 0;
        while(l<=n)
        {
            cout<<l<<" "<<n<<endl;
            res[len++]=l;
            l+=add;
            add+=2;
        }
        for(int i=0; i<len/2; ++i)
        {
            swap(res[i],res[len-i-1]);
        }
        add=2*h;
        LL r = cur;
        while(r<=n)
        {
            res[len++]=r;
            r+=add;
            add+=2;
        }
        for(int i=0;i<len;++i)
        {
            printf("%I64d%c",res[i],(i==len-1)?'\n':' ');
        }
    }
    return 0;
}
