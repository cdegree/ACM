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

int a[111];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; ++i)
        {
            scanf("%d",&a[i]);
        }
        int res=0;
        for(int i=0; i<m; ++i)
        {
            if(a[i]==2||a[i]==3)
            {
                int pos=i;
                int d=1;
                if(a[i]==3)d=-1;
                while(n--)
                {
                    if(d>0)
                    {
                        if(pos+d<m)
                        {
                            pos+=d;
                            if(a[pos]==0)++res;
                        }
                        else
                        {
                            d=-1;
                            pos+=d;
                            if(a[pos]==0)++res;
                        }
                    }
                    else
                    {
                        if(pos+d>=0)
                        {
                            pos+=d;
                            if(a[pos]==0)++res;
                        }
                        else
                        {
                            d=1;
                            pos+=d;
                            if(a[pos]==0)++res;
                        }
                    }
                }
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
