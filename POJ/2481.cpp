/*
BIT
һ��ʼ��ɱ��Լ������ˡ���������Լ����Ļ���ǿ�Ķ����㣬����
�̶�һ�ˣ�Ȼ��Ƚ���һ�ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+1;
int bit[maxn+10],vis[maxn+10];

struct pp{
    int s,e,id;
}seg[maxn+10];

int cmp(const pp &x,const pp &y){   //ע������ķ�ʽ�����Ȱ������Ҷ˽���������������
    if(x.e==y.e)
        return x.s<y.s;
    return x.e>y.e;
}

void add(int i,int v){
    while(i<=maxn){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d%d",&seg[i].s,&seg[i].e);
            seg[i].id=i;
        }
        sort(seg,seg+n,cmp);
        memset(bit,0,sizeof(bit));
        memset(vis,0,sizeof(vis));
        int cnt=1;
        add(seg[0].s+1,1);      //ע���߶ο��Դ�0��ʼ������Ҫ����һ��
        for(i=1;i<n;i++){
            vis[seg[i].id]+=sum(seg[i].s+1);
            if(seg[i].s==seg[i-1].s && seg[i].e==seg[i-1].e){   //Ҫ������ȵ����
                vis[seg[i].id]-=cnt;cnt++;      //���������vis[seg[i].id]=vis[seg[i-1].id],������cnt���û��ǰ�
            }else cnt=1;
            add(seg[i].s+1,1);
        }

        for(i=0;i<n;i++)
            printf("%d%c",vis[i],i==n-1?'\n':' ');
    }
    return 0;
}
