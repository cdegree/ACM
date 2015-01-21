#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int CHILD_NUM = 26;
//��ĸ���С�����û���ʹ�õ��ַ���������Ϊ26��Сд��ĸ���ɸ�,����Ӧ��ӳ��Ҳ��Ҫ��
const int NODE_NUM = 200000;
//��������������*ÿ���û����ĳ��ȡ�

struct NODE {
    int chd[NODE_NUM][CHILD_NUM];
    bool flag[NODE_NUM];//���������
    int ID[CHILD_NUM];//��ϣӳ��
    int sz;
    void Init() {//����ӳ��ȳ�ʼ����
        flag[0] = false;
        memset(chd[0], -1, sizeof(chd[0]));
        sz = 1;
        for(int i = 0; i < 26; ++i) {
            ID[i+'a'] = i;
        }
    }
    void Insert(char *s) {//���������ID
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
    bool Query(char *s) { //��ѯһ��ID�Ƿ��Ǻ�������
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

const int K = 20;//ID����
char s[K];
int main() {
    int n, m;
    BlackList.Init();
    scanf("%d", &n);//���������������
    for(int i = 0; i < n; ++i) {
        scanf("%s", s); //���������ID
        BlackList.Insert(s);
    }
    scanf("%d", &m); //�����ѯ����
    for(int i = 0; i < m; ++i) {
        scanf("%s", s); //�����ѯID
        if(BlackList.Query(s)) {
            printf("���û��ں�����\n");
        }
        else {
            printf("���û����ں�����\n");
        }
    }
}
