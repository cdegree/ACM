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

char s[55];
struct tree
{
    int next[26];
    void init()
    {
        memset(next,-1,sizeof(next));
        cnt=0;
    }
    int cnt;
}Tr[600005];

int bt,root=1,lent;
int res ;
set< pair<int,int> > S;
void insert(int st,int len)
{
    bt = root;
    for(int i=st;i<st+len;++i)
    {
        int id = s[i]-'a';
        if(~(Tr[bt].next[id]))
        {
            bt = Tr[bt].next[id];
        }
        else
        {
            Tr[bt].next[id] = ++lent;
            //if(lent==600005)while(1);
            Tr[lent].init();
            bt = lent;
        }
    }
    pair<int,int>  mp = make_pair(bt,st+len);
    set< pair<int,int> >::iterator it =  S.find(mp);
    for(it = S.begin();it!=S.end();++it)
    {
        if(it->first==bt)
        if( st + len - (it->second) <5 )
        {
            return ;
        }
    }
    ++Tr[bt].cnt;
    S.insert(mp);
    res = max(res,Tr[bt].cnt);
}

int main(int argc, char const *argv[])
{
	int T,n;
	//freopen("Gin.txt","r",stdin);
	//freopen("Gout.txt","w",stdout);
	scanf("%d",&T);

	while(T--)
	{
	    root=1;
	    lent=1;
	    Tr[root].init();
	    scanf("%d",&n);
	    res = 0;
	    for(int i=0;i<n;++i)
	    {
	        scanf("%s",s);
	        int len = strlen(s);
	        if(len<5||s[len-1]==':')continue;
	        for(int j=0;j<len;++j)s[j]=tolower(s[j]);
	        S.clear();
	        for(int j=0;j+5<=len;++j)
	        {
	            insert(j,5);
	        }
	    }
	    if(res!=0)
	    {
	        printf("%d\n",res);
	    }
	    else
	    {
	        puts("Not Found");
	    }

	}
	return 0;
}
