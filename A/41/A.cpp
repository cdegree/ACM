#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>


using namespace std;

string s[]={"Washington" ,"Adams" ,"Jefferson" ,"Madison" ,"Monroe" ,"Adams" ,"Jackson" ,"Van Buren" ,"Harrison" ,"Tyler" ,"Polk" ,"Taylor" ,"Fillmore" ,"Pierce" ,"Buchanan" ,"Lincoln" ,"Johnson" ,"Grant" ,"Hayes" ,"Garfield" ,"Arthur" ,"Cleveland" ,"Harrison" ,"Cleveland" ,"McKinley" ,"Roosevelt" ,"Taft" ,"Wilson" ,"Harding" ,"Coolidge" ,"Hoover" ,"Roosevelt" ,"Truman" ,"Eisenhower" ,"Kennedy" ,"Johnson" ,"Nixon" ,"Ford" ,"Carter" ,"Reagan" ,"Bush" ,"Clinton"};

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while(cin>>n)
	{
		cout<<s[n-1]<<endl;
	}
	return 0;
}