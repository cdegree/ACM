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


int a[5];
bool test_bit(int mask,int pos)
{
    return (mask&(1<<pos))!=0;
}
int count_bit(int mask)
{
    int ret=0;
    for(int i=0; i<6; ++i)
    {
        if(test_bit(mask,i))++ret;
    }
    return ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int res=0;
        memset(a,0,sizeof(a));
        int i;
        for(i=0; i<n; ++i)cin>>a[i];
        if(n<=3)
        {
            cout<<1024<<endl;
            continue;
        }
        else if(n==4)
        {
            for(int mask=0; mask<(1<<4); ++mask)
            {
                if(count_bit(mask)==3)
                {
                    int sum=0;
                    int rest=0;
                    for(i=0; i<4; ++i)
                    {
                        if(test_bit(mask,i))
                        {
                            sum+=a[i];
                        }
                        else rest+=a[i];
                    }
                    if(sum%1024==0)
                    {
                        res=1024;
                        break;
                    }
                }
            }
            if(res!=1024)
            {
                for(int i=0;i<4;++i)
                {
                    for(int j=i+1;j<4;++j)
                    {
                        int t = (a[i]+a[j]);
                        while(t>1024)t-=1024;
                        res = max(res,t);
                    }
                }
            }
        }
        else
        {
            for(int mask=0; mask<(1<<5); ++mask)
            {
                if(count_bit(mask)==3)
                {
                    int sum=0;
                    int rest=0;
                    for(i=0; i<5; ++i)
                    {
                        if(test_bit(mask,i))
                        {
                            sum+=a[i];
                        }
                        else rest+=a[i];
                    }
                    sum%=1024;
                    if(sum==0)
                    {
                        while(rest>1024)rest-=1024;
                        res = max(res,rest);
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
