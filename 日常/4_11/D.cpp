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

int cnt = 4;
inline LL gaorow(int st,int ed)
{
	return ( (1LL<<(st+1) )-1 ) -  ( (1LL<<ed)-1  );
}

inline LL gaocol(int st,int ed)
{
	LL ret = 0 ;
	for(int i=st;i<=ed;i+=6)
	{
		ret |= (1LL<<i);
	}
	return ret;
}

inline bool test_bit(LL mask,int pos)
{
	return mask&(1LL<<pos);
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void pf(LL mask)
{
	for(int j=35;j>=0;--j)
	{
		printf("%d",test_bit(mask,j)?1:0);
		if(j%6==0)puts("");
	}
	puts("");
}

inline bool ok(int x,int y)
{
	return x>=0&&x<6&&y>=0&&y<6;
}

inline bool check(LL mask)
{
	bool OK=false;
	for(int i=0;i<36;++i)
	{
		if( test_bit(mask,i) )
		{
			queue<int> Q;
			Q.push(i);
			bool used[37];
			memset(used,false,sizeof(used));
			int ccnt=0;
			used[i]=true;
			while(!Q.empty())
			{
				int cur = Q.front();
				++ccnt;
				int cx = cur / 6;
				int cy = cur % 6;
				Q.pop();
				for(int k=0;k<4;++k)
				{
					int x = cx + dx[k] ;
					int y = cy + dy[k] ;
					int now = x * 6 + y;
					if(ok(x,y)&&test_bit(mask,now)&&!used[now])
					{
						Q.push(now);
						used[now]=true;
					}
				}
			}
			//printf("ccnt = %d,cnt = %d\n",ccnt,cnt);
			if(ccnt==cnt)
			{
				OK=true;
			}
			break;
		}
	}
	if(OK)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void get_mask(vector<LL> &ret, LL mask)
{
	//pf(mask);
	while(mask>0)
	{
		//pf(mask);
		if(check(mask))
		{
			//puts("ok");
			ret.push_back(mask);
		}
		mask>>=1;
	}
}

vector<LL> shape0()
{
	vector<LL> ret ;
	LL mask = gaorow(35,32);
	get_mask(ret,mask);
	mask = gaocol(17,35);
	get_mask(ret,mask);
	return ret;
}

vector<LL> shape1()
{
	vector<LL> ret ;
	LL mask = gaorow(35,33)|gaocol(29,35);
	get_mask(ret,mask);
	mask = gaorow(23,22)|gaocol(23,35);
	get_mask(ret,mask);
	mask = gaorow(29,27)|gaocol(27,33);
	get_mask(ret,mask);
	mask = gaorow(35,34)|gaocol(22,34);
	get_mask(ret,mask);
	//printf("B: ret.len = %d\n",ret.size());
	return ret;
}

vector<LL> shape2()
{
	vector<LL> ret;
	LL mask = gaorow(35,33)|gaocol(28,34);
	get_mask(ret,mask);
	mask = gaorow(29,28)|gaocol(23,35);
	get_mask(ret,mask);
	mask = gaorow(29,27)|gaocol(28,34);
	get_mask(ret,mask);
	mask = gaorow(29,28)|gaocol(22,34);
	get_mask(ret,mask);
	return ret;
}

vector<LL> shape3()
{
	vector<LL> ret;
	LL mask = gaorow(35,33)|gaocol(27,33);
	get_mask(ret,mask);
	mask = gaorow(35,34)|gaocol(23,35);
	get_mask(ret,mask);
	mask = gaorow(29,27)|gaocol(29,35);
	get_mask(ret,mask);
	mask = gaorow(23,22)|gaocol(22,34);
	get_mask(ret,mask);
	return ret;
}

vector<LL> shape4()
{
	vector<LL> ret;
	LL mask = gaorow(35,34)|gaorow(28,27);
	get_mask(ret,mask);
	mask = gaocol(23,29)|gaocol(28,34);
	get_mask(ret,mask);
	return ret;
}

vector<LL> shape5()
{
	vector<LL> ret;
	LL mask = gaorow(35,34)|gaorow(29,28);
	get_mask(ret,mask);
	return ret;
}

vector<LL> shape6()
{
	vector<LL> ret;
	LL mask = gaorow(34,33)|gaorow(29,28);
	get_mask(ret,mask);
	mask = gaocol(29,35)|gaocol(22,28);
	get_mask(ret,mask);
	return ret;
}

vector<LL> get_result(int idx)
{
	switch(idx)
	{
		case 0:return shape0();
		case 1:return shape1();
		case 2:return shape2();
		case 3:return shape3();
		case 4:return shape4();
		case 5:return shape5();
		case 6:return shape6();
	}
}

inline bool subcheck(LL mask1,LL mask2)
{
	return !(mask1&mask2);
}

inline bool check2(LL mask1,LL mask2,LL mask3)
{
	return subcheck(mask1,mask2)&&subcheck(mask1,mask3)&&subcheck(mask2,mask3);
}

vector<LL> final_res(int a,int b,int c)
{
	vector<LL> va = get_result(a);
	vector<LL> vb = get_result(b);
	vector<LL> vc = get_result(c);

	//printf("len1 = %d ,len2 = %d , len3 = %d\n",va.size(),vb.size(),vc.size());

	vector<LL> ret ;

	for(int i=0;i<va.size();++i)
	{
		for(int j=0;j<vb.size();++j)
		{
			for(int k=0;k<vc.size();++k)
			{
				if(check2(va[i],vb[j],vc[k]))
				{
					ret.push_back(va[i]|vb[j]|vc[k]);
				}
			}
		}
	}
	return ret;

}

void gao()
{
	int T;
	scanf("%d",&T);
	char s[8];
	for(int t=1;t<=T;++t)
	{
		scanf("%s",s);
		vector<LL> now = final_res(s[0]-'A',s[1]-'A',s[2]-'A');
		//printf("len = %d\n",now.size());
		set<LL> myset;
		for(int j=0;j<now.size();++j)
		{
			myset.insert(now[j]);
		}
		scanf("%s",s);
		now = final_res(s[0]-'A',s[1]-'A',s[2]-'A');
		sort(now.rbegin(),now.rend());
		bool found=false;
		LL ans = 0 ;
		for(int j=0;j<now.size();++j)
		{
			if(myset.find(now[j])!=myset.end())
			{
				ans = now[j];
				found=true;
				break;
			}
		}
		printf("%d\n",t);
		if(!found)
		{
			puts("No solution");
		}
		else 
		{
			for(int i=35;i>=0;--i)
			{
				printf("%c",test_bit(ans,i)?'#':'.');
				if(i%6==0)puts("");
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("Din.txt","r",stdin);
	gao();
	return 0;
}