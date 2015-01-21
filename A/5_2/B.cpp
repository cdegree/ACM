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

string s[]={"HELLO"
,"HOLA"
,"HALLO"
,"BONJOUR"
,"CIAO"
,"ZDRAVSTVUJTE"};

string t[]={
	 "ENGLISH","SPANISH","GERMAN"
,"FRENCH","ITALIAN","RUSSIAN"
};
int main(int argc, char const *argv[])
{
	string cc;
	int T=0;;
	while(cin>>cc)
	{
		if(cc[0]=='#')
		{
			break;
		}
		printf("Case %d: ",++T);
		bool found=false;
		for(int i=0;i<6;++i)
		{
			if(s[i]==cc)
			{
				found=true;
				cout<<t[i]<<endl;
			}
		}
		if(!found)
		{
			cout<<"UNKNOWN"<<endl;
		}
	}
	return 0;
}