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

int id[333];
int a[333],b[333],c[333];
void pf(int *t,int n)
{
    for(int i=0; i<n; ++i)printf("%d",t[i]);
    puts("");
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; ++i)a[i]=i,b[i]=i,c[i]=i;
        bool ok=false;
            do
            {
                ok=true;
                //printf("yeee\n");
                for(int i=0; i<n; ++i)
                {
                    if( ((a[i]+b[i])%n)!= c[i] )ok=false;
                }
                if(ok)break;
            }
            while(next_permutation(c,c+n));
        if(ok)
        {
            pf(a,n);
            pf(b,n);
            pf(c,n);
        }
        else
        {
            puts("NO");
        }

    }
    return 0;
}
