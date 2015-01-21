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
const int N = 100005;
struct Person
{
    int a,b;
    int id;
}P[N];

bool cmp1(Person a,Person b)
{
    if(a.b==b.b)return a.a<b.a;
    return a.b<b.b;
}
bool cmp2(Person a,Person b)
{
    return a.a<b.a;
}
bool cmp3(Person a,Person b)
{
    return a.a>b.a;
}
int res[N];
int n,p,k;
void pfa()
{
    printf("a:");
    for(int i=0;i<n;++i)
        {
            printf("%d ",P[i].a);
        }
        puts("");
}
void pfb()
{
    printf("b:");
    for(int i=0;i<n;++i)
        {
            printf("%d ",P[i].b);
        }
        puts("");
}
int main()
{

    while(cin>>n>>p>>k)
    {
        int m = p-k;
        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&P[i].a,&P[i].b);
            P[i].id=i+1;
        }
        sort(P,P+n,cmp1);
        int len=0;
       // pfa();
        //pfb();

        sort(P,P+m,cmp2);
        //pfa();
        //pfb();
        int big=-1;
        for(int i=0;i<m;++i)
        {
            res[len++]=P[i].id;
            big=max(big,P[i].b);
        }
        sort(P,P+n,cmp1);
        //pfa();
        //pfb();
        int l=0,r=n-1,mid,ans=-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(big<P[mid].b)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        sort(P+ans,P+n,cmp3);
        //pfa();
        //pfb();
        //printf("ans = %d k  = %d\n",ans,k);
        for(int i=ans;i<ans+k;++i)
        {
            res[len++]=P[i].id;
        }
        for(int i=0;i<p;++i)
        {
            printf("%d ",res[i]);
        }
        puts("");
    }
	return 0;
}
