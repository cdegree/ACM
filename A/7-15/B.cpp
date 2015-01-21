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
int mm,ss;
char level[9];
char press[4*606];
LL t_topress[12005*3];
char dir_topress[12005*3];
int cnt_press;
int perfect=0,great=0,good=0,boo=0,miss=0;
int beats;
int score[4*606];
LL stage_score,DB,CB;
int step_perid[4*606];
int spd=0;
vector<int> spdd;
int get_level(char ch)
{
    switch(ch)
    {
    case 'E':
        return 1;
    case 'M':
        return 2;
    case 'H':
        return 3;
    }
}
int get_sec_level(char ch)
{
    switch(ch)
    {
    case 'E':
        return 1000;
    case 'M':
        return 500;
    case 'H':
        return 250;
    }
}

void gao1()
{
    spdd.clear();
    int levelt = get_sec_level(level[0]);
    for(int i=0; i<beats; ++i)
    {
        int pos=-1;
        int tim=i*levelt;
        for(int j=0; j<cnt_press; ++j)
        {
            if(tim<=t_topress[j]&&t_topress[j]<tim+levelt)
            {
                pos=j;
                break;
            }
        }
        if(press[i]!='N')
        {
            spd++;
            step_perid[i]=spd;
            if(~pos)
            {
                if(press[i]==dir_topress[pos])
                {
                    LL bt = t_topress[pos]-tim;
                    if(bt*100<levelt*40)
                    {
                        score[i]=5;
                        ++perfect;
                    }
                    else if(bt*100<levelt*70)
                    {
                        score[i]=4;
                        ++great;
                    }
                    else
                    {
                        score[i]=3;
                        ++good;
                    }
                }
                else
                {
                    score[i]=2;
                    ++miss;
                }
            }
            else
            {
                score[i]=1;
                ++boo;
            }
            spdd.push_back(score[i]);
        }
        else
        {
            score[i]=0;
        }
    }
}

void read()
{
    cnt_press=0;
    scanf("%d:%d",&mm,&ss);
    ss += mm*60;
    scanf("%s",level);
    scanf("%s",press);
    beats = strlen(press);
    while(~scanf("%I64d%s",t_topress+cnt_press,dir_topress+cnt_press))
    {
        ++cnt_press;
    }
}

int get_stage_sc(int lvl)
{
    switch(lvl)
    {
        case 5:return 10;
        case 4:return 5;
        default:return 0;
    }
}
void Stage_Score()
{
    stage_score=0;
    int len = spdd.size();
    LL B = 1000000 * get_level(level[0]);
    LL S = len*(len+1)/2;
    LL BS = B/S;
    for(int i=0;i<len;++i)
    {
        stage_score += (i+1)*get_stage_sc(spdd[i])*BS;
        //cout<<step_perid[i]<<endl;
        //cout<<stage_score<<endl;
    }
    printf("Stage Score: %I64d\n",stage_score);
}
int combo_sc(int lv)
{
    switch(lv)
    {
        case 5:return 55;
        case 4:return 33;
        default:return 0;
    }
}
void Combo()
{
    int c=0;
    CB=0;
    for(int i=0;i<spdd.size();++i)
    {
        if(spdd[i]>=3)
        {
            ++c;
            CB+=combo_sc(spdd[i])*c;
        }
        else
        {
            c=0;
        }
    }
    printf("Combo Bonus: %I64d\n",CB);
}
void print1()
{
    printf("Perfect: %d\n",perfect);
    printf("Great: %d\n",great);
    printf("Good: %d\n",good);
    printf("Boo: %d\n",boo);
    printf("Miss: %d\n",miss);
    puts("--------------------");
}

int get_dance(int lv)
{
    switch(lv)
    {
        case 5:return 2;
        case 4:return 1;
        case 3:return 0;
        case 2:return -5;
        case 1:return -4;
    }
}
void Dance()
{
    int n =spdd.size();
    LL mx = n*2;
    LL rx=0;
    for(int i=0;i<n;++i)
    {
        rx += get_dance(spdd[i]);
        if(rx<0)
        {
            printf("Dance Level Bonus: %I64d\n",DB=0);
            return ;
        }
    }

    bool two=true;
    for(int i=0;i<n;++i)
    {
        if(spdd[i]!=5&&spdd[i]!=4)
        {
            two=false;
        }
    }
    DB=0;
    if(rx==mx)
    {
        DB=10000000;
    }
    else if(two)
    {
        DB=1000000;
    }
    else if(100*rx>=mx*80)
    {
        DB=100000;
    }
    else if(100*rx>=mx*64)
    {
        DB=10000;
    }
    else if(100*rx>=mx*50)
    {
        DB=1000;
    }
    else if(rx>=0)
    {
        DB=100;
    }
    printf("Dance Level Bonus: %I64d\n",DB);
}
int main()
{
    freopen("Bin.txt","r",stdin);
    read();
    gao1();
    print1();
    Stage_Score();
    Combo();
    Dance();
    LL tot = stage_score+CB+DB;
    printf("Total Score: %I64d\n",tot);
    return 0;
}
