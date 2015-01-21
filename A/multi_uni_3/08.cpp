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
#pragma comment(linker,"/STACK:102400000,102400000")
int res;
const int inf=1e7;
const int N = 100007;
struct Tree
{
    int next[28];
    int val;
    void init()
    {
        val=-1;
        memset(next,-1,sizeof(next));
    }
} Tr[N];
int len=0;
void insert(char *s,int val)
{
    int i=0;
    int rt=0;
    while(s[i])
    {
        int id;
        if(s[i]>='a'&&s[i]<='z')id=s[i]-'a';
        //else while(1);
        if(~Tr[rt].next[id])
        {
            rt=Tr[rt].next[id];
        }
        else
        {
            rt=Tr[rt].next[id]=len++;
            Tr[len-1].init();
        }
        ++i;
    }
    //printf("%s = %d\n",s,val);
    Tr[rt].val=val;
}
int query(char *s)
{
    int rt=0;
    int i=0;
    bool ok=true;
    while(s[i])
    {
        int id=s[i]-'a';
        if(s[i]>='a'&&s[i]<='z')id=s[i]-'a';
        //else while(1);
        if(~Tr[rt].next[id])
        {
            rt=Tr[rt].next[id];
        }
        else
        {
            ok=false;
            break;
        }
        ++i;
    }
    if(ok)
    {
        return Tr[rt].val;
    }
    else
    {
        return -1;
    }
}
void init()
{
    len=1;
    Tr[0].init();
}

int gao(vector<char> ch);
vector<int> Rp[19];
int gao2(int L,int R,vector<char> ch,vector<int> idx)
{
    int ret=inf;
    bool found=false;
    //printf("%d -> %d\n",L,R);

    for(int i=L+1; i<R; ++i)
    {
        found=false;
        for(int j=i+1; j<R; ++j)
        {
            if(ch[i]==ch[j])
            {
                vector<int> er_idx=idx;
                ret=min(ret,gao2(i+1,j,ch,er_idx));
                er_idx.push_back(i);
                er_idx.push_back(j);
                ret=min(ret,gao2(i,j,ch,er_idx));
                found=true;
            }
        }
    }
    if(!found)
    {
        sort(idx.begin(),idx.end());
        for(int i=L+1; i<R; ++i)
        {
            //printf("i=%d\n",i);
            vector<char> vchar = ch;
            vchar.erase(vchar.begin()+i);
            for(int j=idx.size()-1; j>=0; --j)
            {
                int eid=idx[j];
                if(eid<i)vchar.erase(vchar.begin()+eid);
                else vchar.erase(vchar.begin()+eid-1);
            }
            ret = min(ret,gao(vchar)+1);
        }
        if(L+1>R-1)
        {
            vector<char> vchar = ch;
            for(int i=idx.size()-1; i>=0; --i)
            {
                //printf("pos = %d\n",idx[i]);
                vchar.erase(vchar.begin()+idx[i]);
            }
            //printf("ret =%d\n",ret);
            ret = min(ret,gao(vchar)+1);
        }
        //printf("ret = %d\n",ret);
        return ret;
    }
    else
    {
        return ret;
    }
}

int gao(vector<char> ch)
{
    if(ch.size()==0)
    {
        return 0;
    }
    else if(ch.size()==1)
    {
        return 1;
    }
    else
    {
        char cc[19];
        for(int i=0; i<ch.size(); ++i)
        {
            cc[i]=ch[i];
            //printf("%c",ch[i]);
        }
        for(int i=0; i<19; ++i)
        {
            Rp[i].clear();
        }
        //puts("");
        cc[ch.size()]='\0';
        int ans = query(cc);
        if(~ans)
        {
            return ans;
        }

        int l=0,r=ch.size()-1;
        int prel=l-1,prer=r+1;
        int ret = inf;
        for(int i=0; i<ch.size(); ++i)
        {
            int lent=Rp[i].size();
            for(int j=i+1; j<ch.size(); ++j)
            {
                if(ch[i]==ch[j])
                {
                    vector<int> to_be_erased_idx;
                    to_be_erased_idx.push_back(i);
                    to_be_erased_idx.push_back(j);
                    //printf("here\n");
                    ret = min(ret,gao2(i,j,ch,to_be_erased_idx));
                }
            }
            vector<char> vchar = ch;
            vchar.erase(vchar.begin()+i);
            ret = min(ret,gao(vchar)+1);
        }
        insert(cc,ret);
        return ret;
    }
}
char s[22];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%s",s);
        int cnt1 = strlen(s);
        //if(cnt>16)while(1);
        vector<char> vc;
        int cnt[28]={0};
        for(int i=0; i<cnt1; ++i)
        {
            cnt[ s[i]-'a' ]++;
            vc.push_back(s[i]);
        }
        int ccnt=0;
        for(int i=0;i<26;++i)
        {
            if(cnt[i]>0)
            ++ccnt;
        }
        if(ccnt==1)
        {
            puts("1");
            continue;
        }
        else if(ccnt==2)
        {
            puts("2");
            continue;
        }
        res = gao(vc);
        //printf("len = %d\n",len);
        printf("%d\n",res);
    }
    return 0;
}
