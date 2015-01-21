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
struct Result
{
    string s;
}R[303];

int get_n(string s)
{
    set<string> sets;
    sets.clear();
    for(int i=0;i<s.size();++i)
    {
        for(int j=i;j<s.size();++j)
        {
            sets.insert(s.substr(i,j-i+1));
        }
    }
    return (int)sets.size();
}
string ori;
int spc[27];
void init()
{
    int c=1;
    for(int i=1;i<26;++i)
    {
        spc[i]=c;
        c+=i;
        printf("%d:%d\n",i,spc[i]);
    }
    ori="";
    for(int i=0;i<25;++i)
    {
        ori+=('a'+i);
    }
    cout<<ori<<endl;
    for(int i=0;i<303;++i)
    R[i].s="zzzzzzzzzzzzzzzz";
}
void gao(int u,int n,char *s,char pre)
{
    if(u==n)
    {
        //cout<<s<<endl;
        string tmp="";
        for(int i=0;i<n;++i)
        {
            tmp += s[i];
        }
        int id = get_n(tmp);
        if(R[id].s.size()>tmp.size()||(R[id].s.size()==tmp.size()&&R[id].s>tmp ) )
        {
            R[id].s=tmp;
        }
        return ;
    }

    for(int i=0;i<9;++i)
    {
        if(i>u||abs(pre-ori[i])>3)continue;
        s[u]=ori[i];
        gao(u+1,n,s,s[u]);
    }
}
void pregao()
{
    for(int i=2;i<10;++i)
    {
        char s[15];
        s[0]='a';
        gao(1,i,s,'a');
    }
}
int main()
{
    //cout<<get_n("ab")<<endl;
    init();
    pregao();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        printf("%d : %s\n",i,R[i].s.c_str());
    }
	return 0;
}
