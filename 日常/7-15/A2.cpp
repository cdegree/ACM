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

struct Tree
{
    int next[26];
    vector<int> belong;
    int prefix[15];
    void Clear()
    {
        belong.clear();
        memset(prefix,-1,sizeof(prefix));
        memset(next,-1,sizeof(next));
    }
}Tr[255005];

int len,root;int res[15005][22];
void init()
{
    len=0;
    Tr[0].Clear();
    memset(res,-1,sizeof(res));
}

void Insert(char *s,int idx)
{
    int i=0;
    int u=0;
    while(s[i])
    {
        int id=s[i]-'a';
        if(~Tr[u].next[id])
        {
            u = Tr[u].next[id];
        }
        else
        {
            Tr[u].next[id] = ++len;
            u=len;
            Tr[len].Clear();
        }
        ++i;
    }
    //printf("%d:  %d\n",u,idx);
    Tr[u].belong.push_back(idx);
}

char txt[100005][17];
int freq[100005];
char pre[15005][17];

int n,m;
void push(char *s,int j)
{
    int i=0,rt=0;
    //printf("s = %s\n",s);
    while(s[i])
    {
        int id=s[i]-'a';
        if(~Tr[rt].next[id])
        {
            rt = Tr[rt].next[id];
            for(int q=0;q<Tr[rt].belong.size();++q)
            if(~Tr[rt].belong[q])
            {
                int be = Tr[rt].belong[q];
                int len = res[be][0];
                int k;
                for(k=len;k>=1;--k)
                {
                    if(freq[ res[be][k] ]>freq[j])
                    {
                        break;
                    }
                    else if(freq[ res[be][k] ]==freq[j])
                    {
                        if( strcmp(txt[ res[be][k] ], txt[j])<0 )
                        {
                            break;
                        }
                    }
                }
                //printf("pk = %d\n",k);
                ++k;
                for(int p=len+1;p>k;--p)
                {
                    res[be][p]=res[be][p-1];
                }
                //printf("k = %d\n",k);
                res[be][k]=j;
                if(len<10)++len;
                res[be][0]=len;
            }
        }
        else
        {
            break;
        }
        ++i;
    }
}
void gao()
{
    for(int i=0;i<n;++i)
    {
        push(txt[i],i);
    }
    for(int i=0;i<m;++i)
    {
        //printf(" n  =%d\n",res[i][0]);
        for(int j=1;j<=res[i][0];++j)
        {
            printf("%s\n",txt[ res[i][j] ]);
        }
        if(i!=m-1)puts("");
    }
}


int main()
{

    while(~scanf("%d",&n))
    {
        init();
        for(int i=0;i<n;++i)
        {
            scanf("%s%d",txt[i],freq+i);
        }
        scanf("%d",&m);

        for(int i=0;i<m;++i)
        {
            scanf("%s",pre[i]);
            Insert(pre[i],i);
            res[i][0]=0;
        }
        gao();
    }
	return 0;
}
