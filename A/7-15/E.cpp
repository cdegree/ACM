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
    string s;
    string dig;
} nd[100005];
LL stoll(string s)
{
    LL ret = 0;
    LL e = 1;
    for(int i=s.size()-1;i>=0;--i)
    {
        ret += (s[i]-'0')*e;
        e *= 10;
    }
    return ret;
}

bool cmp(node a,node b)
{
    if(a.s==b.s)
    {
        string t1 = a.dig;
        string t2 = b.dig;
        if(t1.size()<t2.size())
        {
            reverse(t1.begin(),t1.end());
            while(t1.size()<t2.size())
            {
                t1+='0';
            }
            reverse(t1.begin(),t1.end());
        }
        else
        {
            reverse(t2.begin(),t2.end());
            while(t1.size()>t2.size())
            {
                t2+='0';
            }
            reverse(t2.begin(),t2.end());
        }
        for(int i=0;i<t1.size();++i)
        {
            if(t1[i]!=t2[i])
            {
                return t1[i]<t2[i];
            }
        }
        return 1;
    }
    else
    {
        return a.s<b.s;
    }
}
void gao(int id,string s)
{
    int pos=-1;
    for(int i=s.size()-1; i>=0; --i)
    {
        if(isdigit(s[i]))
        {
            pos=i;
        }
        else
        {
            break;
        }
    }
    if(~pos)
    {
        nd[id].s=s.substr(0,pos);
        nd[id].dig=s.substr(pos,s.size()-pos);
    }
    else
    {
        nd[id].s=s;
        nd[id].dig="";
    }
}

int main()
{
    char s[55];
    int n;
    int cnt=0;
    string tmp;
    freopen("Ein.txt","r",stdin);
    while(cin>>tmp)
    {
        gao(cnt++,tmp);
        //cout<<nd[cnt-1].s<<nd[cnt-1].dig<<endl;
        //if(cnt==4)break;
    }
    sort(nd,nd+cnt,cmp);
    //puts("ok");
    for(int i=0; i<cnt; ++i)
    {
        cout<<nd[i].s<<nd[i].dig<<endl;
    }
    return 0;
}
