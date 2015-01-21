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

using namespace std;

typedef long long LL ;

map<string,int> mp;
int n;
int maxlen;
char s[88];
struct person
{
    string first,last,res;
};
person p[202];
int main()
{
    int T=0;
    while(true)
    {
        mp.clear();
        scanf("%d %d",&n,&maxlen);
        //printf("%d %d\n",n,maxlen);
        gets(s);
        if(n==0&&maxlen==0)break;
        for(int i=0; i<n; i++)
        {
            gets(s);
            int len = strlen(s);
            //printf("len = %d\n",len);
            p[i].first="";
            p[i].last="";
            p[i].first += tolower(s[0]);
            for(int j=len-1; j>=0; j--)
            {
                //printf("j = %d\n",j);
                if(isalpha(s[j]))
                {
                    p[i].last += tolower(s[j]);
                }
                else if(s[j]==' ')
                {
                    break;
                }
            }
            p[i].res="";
            reverse(p[i].last.begin(),p[i].last.end());
            p[i].res = p[i].first + p[i].last ;
            //cout<<"ori:"<<p[i].res<<endl;
            while(p[i].res.size()>maxlen)p[i].res.erase(p[i].res.begin()+p[i].res.size()-1 );
        }
        cout<<"Case "<<++T<<endl;
        mp.clear();
        for(int i=0; i<n; ++i)
        {
            //cout<<"ori:"<<p[i].res<<endl;
            if(mp.find(p[i].res)==mp.end())
            {
                cout<<p[i].res<<endl;
                mp[p[i].res]=0;
            }
            else
            {
                int cnt = ++mp[p[i].res];
                if(cnt<10)
                {
                    p[i].res += cnt+'0';
                    while(p[i].res.size()>maxlen)p[i].res.erase(p[i].res.begin()+p[i].res.size()-2 );
                }
                else
                {
                    p[i].res += (cnt)/10 + '0';
                    p[i].res += (cnt)%10 + '0';
                    while(p[i].res.size()>maxlen)p[i].res.erase(p[i].res.begin()+p[i].res.size()-3 );
                }
                cout<<p[i].res<<endl;
            }
        }


    }
    return 0;
}
