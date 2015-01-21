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

int cnt[28],res[28];
int n;
bool judge(int mid)
{
    int sum=0;
    for(int i=0; i<26; ++i)
    {
        sum +=  (cnt[i]+mid-1)/mid;
        res[i] = (cnt[i]+mid-1)/mid;
    }
    return sum<=n;
}
int main()
{
    string s;

    while(cin>>s>>n)
    {
        int len = s.size();
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<len; ++i)
        {
            cnt[ s[i]-'a' ]++;
        }
        len=0;
        for(int i=0; i<26; ++i)
        {
            if(cnt[i ]>0)
            {
                ++len;
            }
        }
        if(len>n)
        {
            puts("-1");
        }
        else
        {
            int l,r,mid,ans=-1;
            l=1,r=1e8;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(judge(mid))
                {
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }

            judge(ans);
            printf("%d\n",ans);
            for(int i=0; i<26; ++i)
            {
                //printf("%d:",res[i]);
                while(res[i]>0)
                {
                    --res[i];
                    --n;
                    printf("%c",i+'a');
                }
            }
            while(n--)printf("a");
            puts("");
        }
    }
    return 0;
}
