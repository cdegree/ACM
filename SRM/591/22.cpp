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

const int N = 2000;
set< pair<int,int> > sp;
int a[N],b[N];
int len;

int main()
{
    int n,m;
    //while(~scanf("%d%d",&n,&m))
    for(int m=2;m<=20;++m,puts(""))
    for(int n=2;n<=m;++n)
    {
         int nn =2*n-2;
         int mm =2*m-2;
        int g = __gcd(nn,mm);
        int lcm = nn*mm/g;
        //printf("   %d %d = %d\n",nn,mm,lcm/nn);
        sp.clear();
        //printf("1");
        len=0;
        a[len++]=1;
        for(int i=1;i<=lcm/nn;++i)
        {
            for(int j=2;j<=n;++j)
            {
                //printf(" %d",j);
             a[len++]=j; }
            for(int j=n-1;j>=1;--j){
                //printf(" %d",j);
                a[len++]=j; }
        }
        //puts("");
        len=0;
        //printf("1");
        b[len++]=1;
        for(int i=1;i<=lcm/mm;++i)
        {
            for(int j=2;j<=m;++j)
            {
                //printf(" %d",j);
                b[len++]=j; }
            for(int j=m-1;j>=1;--j){
                //printf(" %d",j);
                b[len++]=j; }
        }
        //puts("");
        for(int i=0;i<len;++i)
        {
            sp.insert(make_pair(a[i],b[i]));
        }
        printf("%4d",sp.size());
    }
	return 0;
}
