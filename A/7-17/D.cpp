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
    int T;
    scanf("%d",&T);
    while(T--)
    {
        string s;
        cin>>s;
        bool OK=true;
        int n = s.size();
        for(int i=0;i<n/2;++i)
        {
            if(s[i]!=s[n-i-1])
            {
                OK=false;
            }
        }
        printf("%s\n",OK?"YES":"NO");
    }
	return 0;
}
