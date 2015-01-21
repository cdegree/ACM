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
struct node
{
    string s[3];
}nd[22];
int rank[22];
string res[22];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>nd[i].s[j];
            }
            sort(nd[i].s,nd[i].s+3);
        }
        for(int i=0;i<n;i++)scanf("%d",rank+i);
        bool ok=true;
        string last="";
        for(int i=0;i<n;i++)
        {
            int cur = rank[i]-1;
            bool found=false;
            for(int j=0;j<3;j++)
            {
                if( last<nd[cur].s[j] )
                {
                    res[i]=nd[cur].s[j];
                    last=res[i];
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            for(int i=0;i<n;i++)
            {
                cout<<res[i]<<endl;
            }
        }
        else
        {
            puts("IMPOSSIBLE");
        }
    }
	return 0;
}
