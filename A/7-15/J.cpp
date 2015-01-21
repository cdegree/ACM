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

typedef long long LL;


map<string,int> mp;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int m=(1<<n);
        string s,t;
        int mx=0;
        for(int i=0;i<m;++i)
        {
            cin>>s>>t;
            mp[t]++;
            mx=max(mx,mp[t]);
        }
        int ans=0;
        for(int i=0;i<=n;++i)
        {
            if((1<<i)>=mx)
            {
                ans=n-i;
                break;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
