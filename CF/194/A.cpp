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

int mt[105][105];

int main()
{
    int n;
    while(cin>>n)
    {
        int m = sqr(n);
        int len=1;
        for(int j=0; j<n; ++j)
        {
            if(j&1)
            {
                for(int i=n-1; i>=0; --i)
                {
                    mt[i][j]=len++;
                }
            }
            else
            {
                for(int i=0; i<n; ++i)
                {
                    mt[i][j]=len++;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                printf("%d ",mt[i][j]);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
