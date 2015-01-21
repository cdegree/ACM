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
using namespace std;

typedef long long LL ;

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;++i)
        {
            if(i==0)
            {
                printf("0 ");
                for(int j=1;j<n;++j)
                {
                    printf("1 ");
                }
                puts("");
            }
            else if(i==1)
            {
                printf("1 ");
                for(int j=1;j<n;++j)
                {
                    printf("10 ");
                }
                puts("");
            }
            else
            {
                for(int j=0;j<n;++j)
                {
                    printf("0 ");
                }
                puts("");
            }
        }
    }
	return 0;
}
