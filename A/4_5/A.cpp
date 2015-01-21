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
const double eps = 1e-8 ;
typedef long long LL ;
const int N = 100005;
string s,t;

map<string,string> mp;
char str[111];
vector<string> tostring()
{
	string tmp = "";
	int i=0;
	vector<string> vs;
	vs.clear();
	int len =strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			vs.push_back(tmp);
			//cout<<"tmp = "<<tmp<<endl;
			tmp="";
		}
		else
		{
			tmp+=str[i];
		}
	}
	//cout<<"tmp = "<<tmp<<endl;
	vs.push_back(tmp);
	return vs;
}
int main(int argc, char const *argv[])
{
	int T;
	freopen("Ain.txt","r",stdin);
	cin>>T;
	for(int _t=1;_t<=T;++_t)
	{
		int n,m;
		cin>>n>>m;
		//printf("m = %d\n", m);
		mp.clear();
		for(int i=0;i<m;i++)
		{
			cin>>s>>t;
			//cout<<s<<" "<<t<<endl;
			mp[s]=t;
		}
		getchar();
		gets(str);
		//printf("%s\n",str );
		vector<string> res = tostring();
		for(int i=0;i<res.size();++i)
		{
			int k=1;
			while(mp.find(res[i])!=mp.end()&&k<n)
			{
				++k;
				//cout<<"res = "<<res[i]<<endl;
				res[i]=mp[res[i]];
			}
		}
		//cout<<"len = "<<(int)res.size()<<endl;
		printf("Case #%d:",_t);
		for(int i=0;i<res.size();++i)
		{
			cout<<" "<<res[i];
		}
		cout<<endl;
	}
	return 0;
}