#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int CHILD_NUM = 26;
//字母表大小，即用户名使用的字符数量。此为26个小写字母，可改,但相应的映射也需要改
const int NODE_NUM = 200000;
//总容量，黑名单*每个用户名的长度。

struct NODE {
    int chd[NODE_NUM][CHILD_NUM];
    bool flag[NODE_NUM];//黑名单标记
    int ID[CHILD_NUM];//哈希映射
    int sz;
    void Init() {//建立映射等初始化。
        flag[0] = false;
        memset(chd[0], -1, sizeof(chd[0]));
        sz = 1;
        for(int i = 0; i < 26; ++i) {
            ID[i+'a'] = i;
        }
    }
    void Insert(char *s) {//插入黑名单ID
        int p = 0;
        for(; *s; ++s) {
            int c = ID[*s];
            if(chd[p][c] == -1) {
                memset(chd[sz], -1, sizeof(chd[sz]));
                flag[sz] = false;
                chd[p][c]=sz++;
            }
            p = chd[p][c];
        }
        flag[p] = true;
    }
    bool Query(char *s) { //查询一个ID是否是黑名单。
        int p = 0;
        bool found = false;
        for(; *s; ++s) {
            found=false;
            int c = ID[*s];
            if(chd[p][c] == -1) {
                break;
            }
            else {
                p = chd[p][c];
                if(flag[p]) {
                    found = true;
                }
            }
        }
        return found;
    }
} BlackList;

const int K = 20;//ID长度
char s[K];
int main() {
    int n, m;
    BlackList.Init();
    scanf("%d", &n);//输入黑名单数量。
    for(int i = 0; i < n; ++i) {
        scanf("%s", s); //输入黑名单ID
        BlackList.Insert(s);
    }
    scanf("%d", &m); //输入查询数量
    for(int i = 0; i < m; ++i) {
        scanf("%s", s); //输入查询ID
        if(BlackList.Query(s)) {
            printf("此用户在黑名单\n");
        }
        else {
            printf("此用户不在黑名单\n");
        }
    }
}
