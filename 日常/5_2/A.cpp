#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;

typedef long long LL ;

string merge(string a,string b)
{
    string ret = a;
    int pos=a.size();
    for(int i=0;i<b.size();++i)
    {
        int st = a.size() - b.size() + i;
        bool ok = true;
        if(st<0)continue;
        for(int j=0;j+st<a.size();++j)
        {
            if(a[st+j]!=b[j])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            pos = st;
            break;
        }
    }
    //printf("pos = %d\n",pos);
    ret = a.substr(0,pos) + b;
    return ret;
}
string s[9];
int main(int argc, char const *argv[])
{
    string a="abc";
    string b="bcd";
    //out<<merge(a,b)<<endl;
    int T=0;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)cin>>s[i];
        int id[]={0,1,2,3,4,5,6};
        int res=100000;
        do
        {
            string ret=s[id[0] ];
            for(int i=1;i<n;++i)
            {
                ret = merge(ret,s[id[i]]);
            }
            res = min(res,(int)ret.size());

        }while(next_permutation(id,id+n));

        printf("Case %d: ",t);
        cout<<res<<endl;

    }
	return 0;
}
