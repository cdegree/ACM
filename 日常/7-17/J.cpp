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

struct Room
{
    pair<int,int> sw;
    pair<int,int> ne;
    int id;
    friend bool operator <(const Room &a,const Room &b)
    {
        if(a.sw>b.sw&&a.ne<b.ne)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    friend bool operator >(const Room &a,const Room &b)
    {
        if(a.sw<b.sw&&a.ne>b.ne)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    friend bool operator ==(const Room &a,const Room &b)
    {
        if(a.sw<b.sw&&a.ne>b.ne)
        {
            return 0;
        }
        else if(a.sw>b.sw&&a.ne<b.ne)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
} R[100005];

int cmp(Room a,Room b)
{
    if(a.sw<b.sw&&a.ne>b.ne)
    {
        return 1;
    }
    else if(a.sw>b.sw&&a.ne<b.ne)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
bool xcmp(Room a,Room b)
{
    return cmp(a,b)<0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        int x,y,x1,y1;
        scanf("%d%d%d%d",&x,&y,&x1,&y1);
        R[i].id=i;
        R[i].sw=make_pair(x,y);
        R[i].ne=make_pair(x1,y1);
    }
    sort(R,R+n,xcmp);
    for(int i=0;i<n;++i)
    {
        printf("%d %d -> %d %d\n",R[i].sw.first,R[i].sw.second,R[i].ne.first,R[i].sw.second);
    }
    for(int i=0; i<n; ++i)
    {
        int l=0,r=n-1,mid,ans=-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(cmp(R[i],R[mid])<0)
            {
                ans = R[mid].id;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
