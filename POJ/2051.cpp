/****************
*PID:poj2051
*Auth:Jonariguez
*****************
���ȶ���
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=3000+10;
int p[maxn];

struct Item{
    int q,p;
    Item(int _q=0,int _p=0):q(_q),p(_p){}
    bool operator < (const Item &r) const {
        if(p==r.p)
            return q>r.q;
        return p>r.p;
    }
};

int main()
{
    char str[10];
    int k;
    priority_queue<Item> pq;
    while(scanf("%s",str)){
        if(str[0]=='#') break;
        Item u;
        scanf("%d%d",&u.q,&u.p);
        p[u.q]=u.p;
        pq.push(u);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        Item u=pq.top();pq.pop();
        printf("%d\n",u.q);
        u.p+=p[u.q];            //ȡ����֮���ٰ�p�����Լ�ԭ��������p�ٷŽ�������ȥ����Ҫ��¼ÿ��qid��period����
        pq.push(u);
    }
    return 0;
}
