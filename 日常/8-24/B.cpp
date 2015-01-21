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

char s1[22],s2[22];char s3[22];
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%s%s",s1,s2);
        printf("Case %d: ",t);
        if(strcmp(s1,s2)==0)
        {
            puts("Login successful.");
            continue;
        }
        int n1=strlen(s1),n2=strlen(s2);
        bool ok1=0,ok2=0;
        vector<char> ori;
        for(int i=0;i<n1;++i)ori.push_back(s1[i]);
        for(int i=0;i<ori.size();++i)
        {
            if(isdigit(ori[i]))
            {
                ori.erase(ori.begin()+i);
                --i;
            }
        }
        for(int i=0;i<ori.size();++i)s3[i]=ori[i];
        s3[ori.size()]='\0';
        if(strcmp(s3,s2)==0)
        {
            ok2=1;
        }
        //printf("%s %s  %s\n",s1,s3,s2);
        int n3= strlen(s3);
        if(n1==n2)
        {
            bool ok=1;
            for(int i=0;i<n1;++i)
            {
                if(s1[i]==s2[i]&&!isalpha(s1[i]))continue;
                if(isalpha(s1[i])&&isalpha(s2[i]))
                {
                    if( (tolower(s1[i])==tolower(s2[i]))&& ((islower(s1[i])&&isupper(s2[i])) || (isupper(s1[i])&&islower(s2[i]))) )
                    {
                    }
                    else
                    {
                        ok=0;
                    }
                }
                else
                {
                    ok=0;
                }
            }
            if(ok)
            {
                ok1=ok;
            }
        }
        if(n3==n2&&!ok1)
        {
            bool ok=1;
            for(int i=0;i<n3;++i)
            {
                if(s3[i]==s2[i]&&!isalpha(s2[i]))continue;
                if(isalpha(s3[i])&&isalpha(s2[i]))
                {
                    if((tolower(s3[i])==tolower(s2[i]))&& ((islower(s3[i])&&isupper(s2[i])) || (isupper(s3[i])&&islower(s2[i]))))
                    {
                    }
                    else ok=0;
                }
                else
                {
                    ok=0;
                }
            }
            if(ok)
            {
                ok1=ok;
                ok2=ok;
            }
        }
        if(ok1&&ok2)
        {
            puts("Wrong password. Please, check your caps lock and num lock keys.");
        }
        else if(ok1)
        {
            puts("Wrong password. Please, check your caps lock key.");
        }
        else if(ok2)
        {
            puts("Wrong password. Please, check your num lock key.");
        }
        else
        {
            puts("Wrong password.");
        }
    }
	return 0;
}
