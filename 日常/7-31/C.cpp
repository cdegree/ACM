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

int belong[105];
int rep[105];
int res[10005][2];
int main()
{
    int n,k,m;
    while(cin>>n>>k>>m)
    {
        for(int i=0;i<n;++i)
        {
            belong[ i+1 ]= i%k+1;
        }
        int len=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(belong[i]!=belong[j])
                {
                    res[len][0]=i;
                    res[len++][1]=j;
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d\n",belong[i]);
        }
        for(int i=0;i<m;++i)
        {
            printf("%d %d\n",res[i][0],res[i][1]);
        }

    }
	return 0;
}
