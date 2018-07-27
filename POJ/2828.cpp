#include <stdio.h>
#include <string.h>

const int maxn=200000+10;
//sum��¼�ڵ�Ŀ�λ������dat��������ֵ
int sum[maxn*4],dat[maxn*4],pos[maxn],val[maxn];
int n;

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void build(int k,int l,int r){
    if(l==r){
        sum[k]=1;dat[k]=-1;
        return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);

}

void update(int p,int v,int k,int l,int r){
    if(l==r){
        dat[k]=v;sum[k]--;return ;
    }
    int m=(l+r)/2;
    if(sum[k*2]>=p)         //ע��������>=  һ��ʼд��>�ˣ���
        update(p,v,k*2,l,m);
    else
        update(p-sum[k*2],v,k*2+1,m+1,r);
    pushUp(k);
}

int cnt;
void ask(int k,int l,int r){
    if(l==r){
        printf("%d%c",dat[k],++cnt==n?'\n':' ');return ;
    }
    int m=(l+r)/2;
    ask(k*2,l,m);
    ask(k*2+1,m+1,r);
}

int main()
{
    int i,j,t;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d%d",&pos[i],&val[i]);
        build(1,1,n);
        for(i=n-1;i>=0;i--)         //���Ŵ�����ܽ��һ���������
            update(pos[i]+1,val[i],1,1,n);
        cnt=0;
        ask(1,1,n);
    }
    return 0;
}
