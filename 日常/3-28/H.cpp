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
int n;
struct List
{
    string a,b;
    int no;
}L[1005];
inline bool check(char c)
{
    return c=='M'||c=='T'||c=='W';
}

struct person
{
    string nam;
    int mn,mx;
}P[1005];
int main()
{
    while(cin>>n)
    {

        int len=0;
        for(int i=0;i<n;i++)
        {
            cin>>L[i].a>>L[i].b;
            int mn=0,mx=0;
            if(check(L[i].b[0]))
            {
                cin>>L[i].no;
                if(L[i].no>=6)
                {
                    ++mx;
                }
                if(L[i].no==7)
                {
                    ++mn;
                }
            }
            else if(L[i].b[0]=='A')
            {
                ++mx;
            }
            int idx = -1;
            for(int j=0;j<len;j++)
            {
                if(L[i].a==P[j].nam)
                {
                    idx=j;
                    break;
                }
            }
            if(idx!=-1)
            {
                P[idx].mx=max(P[idx].mx,mx);
                P[idx].mn=max(P[idx].mn,mn);
            }
            else
            {
                P[len].nam=L[i].a;
                P[len].mn=mn;
                P[len++].mx=mx;
            }
        }
        int res1=0,res2=0;
        for(int i=0;i<len;i++)
        {
            //cout<<P[i].nam;
            res1+=P[i].mn;
            res2+=P[i].mx;
        }
        cout<<res1<<" "<<res2<<endl;
    }
	return 0;
}
