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

string s[]={"abc","acb","bac","bca","cab","cba"
};
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==1)
        {
            puts("a");
            puts("b");
            puts("c");
        }
        else if(n*6>100000)
        {
            puts("TOO LONG");
        }
        else
        {
            for(int i=0;i<6;++i)
            {
                int j=0;
                for(int k=0;k<n;++k,j=(j+1)%3)
                {
                    printf("%c",s[i][j]);
                }
                puts("");
            }
        }

    }
	return 0;
}
