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

vector<pair<int,int> > vp,np;
int s[111];
int res[111][2];
int main()
{
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        for(int i=0;i<n;++i)scanf("%d",s+i);
        int sum=b;
        int len=0;
        bool ok=1;
        memset(res,0,sizeof(res));
        for(int i=0;i<n;++i)
        {
            if(sum<s[i])
            {
                if(sum+a>=s[i])
                {
                    res[i][0]=(s[i]-sum);
                    a = a-(s[i]-sum);
                    sum=s[i];
                }
                else ok=0;
            }
            else if(sum>s[i])
            {
                if(sum-b<=s[i])
                {
                    res[i][1]=(sum-s[i]);
                    b = b-(sum-s[i]);
                    sum=s[i];
                }
                else ok=0;
            }
        }
        if(ok)
        {
            for(int i=0;i<n;++i)printf("%d %d\n",res[i][0],res[i][1]);
        }
        else
        {
            puts("ERROR");
        }
    }
	return 0;
}
