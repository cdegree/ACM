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
    char s[22];
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
			mx[rt][0]=L;
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
	    while(l1<len[lc]&&l2<len[rc]&&l<10)
	    {
	        if(W[ mx[lc][l1] ].cnt == W[ mx[rc][l2] ].cnt)
	        {
	            if(strcmp(W[ mx[lc][l1] ].s, W[ mx[rc][l2] ].s)<0)
	            {
	                tmp[l++]=mx[lc][l1++];
	            }
	            else
	            {
	                tmp[l++]=mx[rc][l2++];
	            }
	        }
	        else if(W[ mx[lc][l1] ].cnt > W[ mx[rc][l2] ].cnt)
	        {
	            tmp[l++]=mx[lc][l1++];
	        }
	        else
	        {
	            tmp[l++]=mx[rc][l2++];
	        }
	    }
	    while(l1<len[lc]&&l<10)
	    {
            tmp[l++]=mx[lc][l1++];
	    }
	    while(l2<len[rc]&&l<10)
	    {
            tmp[l++]=mx[rc][l2++];
	    }
	    for(int i=0;i<l;++i)
	    {
	        mx[rt][i]=tmp[i];
	    }
	    len[rt]=l;
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
			int l1=0,l2=0,l=0;
			while(l1<v1.size()&&l2<v2.size()&&l<10)
			{
			    ++l;
			    if(W[v1[l1]].cnt==W[v2[l2]].cnt)
			    {
			        if(strcmp(W[v1[l1]].s,W[v2[l2]].s)<0)
			        {
			            ret.push_back(v1[l1++]);
			        }
			        else
			        {
			            ret.push_back(v2[l2++]);
			        }
			    }
			    else if(W[v1[l1]].cnt>W[v2[l2]].cnt)
			    {
			        ret.push_back(v1[l1++]);
			    }
			    else
			    {
			        ret.push_back(v2[l2++]);
			    }
			}
			while(l1<v1.size()&&l<10)
			{
			    ++l;
			    ret.push_back(v1[l1++]);
			}
			while(l2<v2.size()&&l<10)
			{
			    ++l;
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
    int c = strcmp("a","add");
    //printf("%d\n",c);
    freopen("Ain.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%s%d",W[i].s,&W[i].cnt);
        }
        sort(W+1,W+n+1,cmp);
        //for(int i=1;i<=n;++i)printf("%s %d\n",W[i].s,W[i].cnt);

        Seg.Build(1,n,1);
        //puts("ok1");
        int m;
        scanf("%d",&m);
        char s[25];
        for(int i=0;i<m;++i)
        {
            scanf("%s",s);
            int lb=1000000,ub=-1;
            int l=1,r=n,mid;
            int len = strlen(s);
            char tmp[22];
            while(l<=r)
            {
                mid =(l+r)/2;
                strcpy(tmp,W[mid].s);
                tmp[min(len,(int)strlen(W[mid].s))]='\0';
                int cp = strcmp(s,tmp);
                //printf("from %d ot %d mid %d = %s   %d  %s\n",l,r,mid,s,cp,tmp);
                if(cp==0)
                {
                    lb=min(lb,mid);
                    r = mid - 1;
                }
                else if(cp<0)
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
                tmp[min(len,(int)strlen(W[mid].s))]='\0';
                int cp = strcmp(s,tmp);
                //printf("%s      %s\n",tmp,s);
                if(cp==0)
                {
                    ub=max(ub,mid);
                    l = mid + 1;
                }
                else if(cp<0)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            //printf("%d %d\n",lb,ub);
            if(lb<=ub)
            {
                //printf("%d %d\n",lb,ub);
                vector<int> res = Seg.Query(1,n,1,lb,ub);
                //sort(res.begin(),res.end());
                for(int j=0;j<res.size();++j)
                {
                    //printf("%d = ",res[j]);
                    printf("%s\n",W[ res[j] ].s);
                }
            }
            if(i!=m-1)puts("");
        }
    }
	return 0;
}
