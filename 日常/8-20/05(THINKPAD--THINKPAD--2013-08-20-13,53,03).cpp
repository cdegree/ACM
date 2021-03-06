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



string da[][18]=
{
    {"NUL","SOH","STX","ETX","","HT","","DEL","","","","VT","FF","CR","SO","SI"},
    {"DLE","DC1","DC2","DC3","","","BS","","CAN","EM","","","IFS","IGS","IRS","IUS ITB"},
    {"","","","","","LF","ETB","ESC","","","","","","ENQ","ACK","BEL"},
    {"","","SYN","","","","","EOT","","","","","DC4","NAK","","SUB"},
    {"SP","","","","","","","","","","",".","<","(","+","|"},
    {"&","","","","","","","","","","!","$","*",")",";"},
    {"-","/","","","","","","","","","",",","%","_",">","?"},
    {"","","","","","","","","","`",":","#","@","'","=","\""},
    {"","a","b","c","d","e","f","g","h","i","","","","","",""},
    {"","j","k","l","m","n","o","p","q","r","","","","","",""},
    {"","~","s","t","u","v","w","x","y","z","","","","","",""},
    {"^","","","","","","","","","","[","]","","","",""},
    {"{","A","B","C","D","E","F","G","H","I","","","","","",""},
    {"}","J","K","L","M","N","O","P","Q","R","","","","","",""},
    {"\\","","S","T","U","V","W","X","Y","Z","","","","","",""},
    {"0","1","2","3","4","5","6","7","8","9","","","","","",""}
};
string asc[][18]=
{
    {"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI"},
    {"DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","IFS","IGS","IRS","IUS ITB"},
    {"SP","!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/"},
    {"0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?"},
    {"@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"},
    {"P","Q","R","S","T","U","V","W","X","Y","Z","[","\\","]","^","_"},
    {"`","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"},
    {"p","q","r","s","t","u","v","w","x","y","z","{","|","}","~"},
};
pair<char,char> get_ans(int x,int y)
{
    string t = da[x][y];
    cout<<t<<endl;
    printf("%d %d\n",x,y);
    for(int i=0; i<8; ++i)
    {
        for(int j=0; j<16; ++j)
        {
            if(asc[i][j]==t)
            {
                printf("to %d %d\n",i,j);
                return make_pair(i+'0',(j>9)?('A'+j):('0'+j));
            }
        }
    }
}
char s[100005];
int cton(char ch)
{
    if(ch>='0'&&ch<='9')return ch-'0';
    return ch-'A'+10;
}
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        for(int i=0; i<n; i+=2)
        {
            pair<char,char> vp = get_ans(cton(s[i]),cton(s[i+1]));
            printf("%c%c",vp.first,vp.second);
        }
        puts("");

    }
    return 0;
}
