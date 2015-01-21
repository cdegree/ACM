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


int a[105];
bool obs[2002];
int main()
{
    int n,x;
    while(cin>>n>>x)
    {
        memset(obs,false,sizeof(obs));
        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
            obs[a[i]+1000]=true;
        }
        x+=1000;
        int l=1000,r=1000;
        while(!obs[l])--l;
        while(!obs[r])++r;
        if(l<x&&x<r)
        {
            int back=0,forward=0;
            if(x<1000)
            {
                back=1000-x;
                forward=(r-1000)*2+back;
            }
            else
            {
                forward=x-1000;
                back=(1000-l)*2+forward;
            }
            printf("%d %d\n",forward,back);
        }
        else
        {
            puts("Impossible");
        }
    }
	return 0;
}
