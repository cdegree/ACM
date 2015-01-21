#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>


using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char s[99];
	while(gets(s))
	{
		int len = strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]==' ')
			{
				printf("\"");
				for(int j=i+1;j<len;j++)
				{
					printf("%c",s[j]);
				}
				printf("\",");
				break;
			}
		}
	}
	return 0;
}