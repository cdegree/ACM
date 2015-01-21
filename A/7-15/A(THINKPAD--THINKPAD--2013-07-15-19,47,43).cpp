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

const int maxn = 100005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

struct Words
{
    char s[17];
    int cnt;
}W[maxn];

struct Segment_Tree
{
	int left[maxn*4],right[maxn*4];
	int mx[maxn*4][12];
	int len[maxn*4];
	void Build(int L,int R,int rt)
	{
		left[rt]=L,right[rt]=R;
		len[rt]=mx[rt][0]=0;
		if(L==R)
		{
			mx[rt][0]=W[L].cnt;
			len[rt]=1;
		}
		else
		{
			int mid = (L+R)>>1;
			Build(lson);
			Build(rson);
			Push_Up(rt);
		}
	}
	void Push_Up(int rt)
	{
	    int tmp[22];
	    int l1=0,l2=0,l=0;
	    while(l1<len[lc]||l2<len[rc])
	    {
	        if(mx[lc][l1]>mx[rc][l2])
	        {
	            tmp[l++]=mx[lc][l1++];
	        }
	        else
	        {
	            tmp[l++]=mx[rc][l2++];
	        }
	    }
	    while(l1<len[lc])
	    {
            tmp[l++]=mx[lc][l1++];
	    }
	    while(l2<len[rc])
	    {
            tmp[l++]=mx[rc][l2++];
	    }
	    for(int i=0;i<l&&i<10;++i)
	    {
	        mx[rt][i]=tmp[i];
	    }
	    len[rt]=min(len[lc]+len[rc],10);
	}
	void Push_Down(int rt)
	{
	}
	void Update(int L,int R,int rt,int from,int to,int val)
	{
		if(from<=L&&R<=to)
		{

		}
		else
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			if(from<=mid)
			{
				Update(lson,from,to,val);
			}
			if(to>mid)
			{
				Update(rson,from,to,val);
			}
			Push_Up(rt);
		}
	}
    vector<int> Query(int L,int R,int rt,int from,int to)
	{
	    vector<int> ret;
		if(from<=L&&R<=to)
		{
		    for(int i=0;i<len[rt];++i)
		    {
		        ret.push_back(mx[rt][i]);
		    }
		    return ret;
		}
		else
		{
			int mid = (L+R)>>1;
			Push_Down(rt);
			vector<int> v1,v2;
			if(from<=mid)
			{
				v1 = Query(L,mid,lc,from,to);
			}
			if(to>mid)
			{
				v2 = Query(mid+1,R,rc,from,to);
			}
			int l1=0,l2=0,l=10;
			while((l1<v1.size()||l2<v2.size())&&l>0)
			{
			    --l;
			    if(v1[l1]>v2[l2])
			    {
			        ret.push_back(v1[l1++]);
			    }
			    else
			    {
			        ret.push_back(v2[l2++]);
			    }
			}
			while(l1<v1.size()&&l>0)
			{
			    --l;
			    ret.push_back(v1[l1++]);
			}
			while(l2<v2.size()&&l>0)
			{
			    --l;
			    ret.push_back(v2[l2++]);
			}
			return ret;
		}
	}

}Seg;

bool cmp(Words a,Words b)
{
    return strcmp(a.s,b.s)<0;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%s%d",W[i].s,&W[i].cnt);
        }
        sort(W+1,W+n+1,cmp);
        Seg.Build(1,n,1);
        int m;
        scanf("%d",&m);
        char s[25];
        for(int i=0;i<m;++i)
        {
            scanf("%s",s);
            int lb=-1,ub=-1;
            int l=1,r=n,mid;
            char tmp[22];
            while(l<=r)
            {
                mid =(l+r)/2;
                strcpy(tmp,W[mid].s);
                tmp[strlen(s)]='\n';
                printf("%s %s\n",tmp,s);
                int cp = strcmp(s,tmp);
                if(cp==0)
                {
                    lb=mid;
                    r = mid - 1;
                }
                else if(cp>0)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            l=1,r=n;
            while(l<=r)
            {
                mid =(l+r)/2;
                strcpy(tmp,W[mid].s);
                tmp[strlen(s)]='\n';
                int cp = strcmp(s,tmp);
                if(cp==0)
                {
                    ub=mid;
                    l = mid + 1;
                }
                else if(cp>0)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            printf("%d %d\n",lb,ub);
            if(~lb&&lb<=ub)
            {
                vector<int> res = Seg.Query(1,n,1,lb,ub);
                for(int j=0;j<res.size();++j)
                {
                    printf("%s\n",W[ res[j] ].s);
                }
            }
        }
    }
	return 0;
}
