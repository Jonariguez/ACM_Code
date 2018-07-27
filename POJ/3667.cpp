#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
//sum�Ǹ��������������  lsum�Ǵ���������˿�ʼ��������ȣ�rsum���Ҷˣ�markΪ��� -1�� 0�ÿ� 1����
int sum[maxn*4],lsum[maxn*4],rsum[maxn*4],mark[maxn*4];

int Max(int a,int b,int c){
    return max(a,max(b,c));
}

void pushUp(int k,int l,int r){     //���׽ڵ��lsum��rsum�ֱ�Ϊ����ӵ�lsum���Ҷ��ӵ�rsum
    lsum[k]=lsum[k*2];rsum[k]=rsum[k*2+1];
    int m=(l+r)/2;
    if(lsum[k]==m-l+1)  lsum[k]+=lsum[k*2+1];   //���lsum����������������䣬��ôlsum��Ӧ�ð��Ұ�����(���Ҷ���)��lsum����
    if(rsum[k]==r-m)    rsum[k]+=rsum[k*2];     //ԭ��ͬ��
    sum[k]=Max(sum[k*2],sum[k*2+1],rsum[k*2]+lsum[k*2+1]);      //���׽ڵ��sumӦ�������Ҷ��ӵ�sumֵ�Ϳ�������Ƕ��������� ���ߵ��
}

void pushDown(int k,int l,int r){
    if(mark[k]!=-1){
        mark[k*2]=mark[k*2+1]=mark[k];
        int m=(l+r)/2;
        if(mark[k]==1){             //�����������������ĳ��ȶ���0
            sum[k*2]=lsum[k*2]=rsum[k*2]=sum[k*2+1]=lsum[k*2+1]=rsum[k*2+1]=0;
        }else if(mark[k]==0){
            sum[k*2]=m-l+1;lsum[k*2]=rsum[k*2]=m-l+1;
            sum[k*2+1]=r-m;lsum[k*2+1]=rsum[k*2+1]=r-m;
        }
        mark[k]=-1;
    }
}



void build(int k,int l,int r){
    if(l==r){
        sum[k]=lsum[k]=rsum[k]=1;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k,l,r);
}

void update(int a,int b,int k,int l,int r,int v){
    if(a<=l && b>=r){
        mark[k]=v;      //�����
        if(v)
            sum[k]=lsum[k]=rsum[k]=0;
        else
            sum[k]=lsum[k]=rsum[k]=r-l+1;
        return ;
    }
    pushDown(k,l,r);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,k*2,l,m,v);
    if(b>m)
        update(a,b,k*2+1,m+1,r,v);
    pushUp(k,l,r);
}

int query(int L,int k,int l,int r){
    if(l==r) return l;
    int m=(l+r)/2;
    pushDown(k,l,r);
    if(sum[k*2]>=L)     //ע��������return˳���ܱ䣬��ΪҪ��r��С
        return query(L,k*2,l,m);        //�ݹ�������
    else if(rsum[k*2]+lsum[k*2+1]>=L)
        return m-rsum[k*2]+1;           //��������ǿ���ֱ�ӷ��ؽ����������������һ������rsum��ʾ�����䣬������
    else                                //��L������Ϊ��������֮ǰ����������ϣ��Ͼ�����Ҫ���ǿ�ͷ��С���Ǹ�����
        return query(L,k*2+1,m+1,r);    //�ݹ�������
}

int main()
{
    int i,n,m,p,x,d;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    memset(mark,-1,sizeof(mark));
    while(m--){
        scanf("%d",&p);
        if(p==1){
            scanf("%d",&d);
            if(sum[1]<d){
                printf("0\n");
                continue;
            }
            int t=query(d,1,1,n);
            printf("%d\n",t);
            update(t,t+d-1,1,1,n,1);
        }else {
            scanf("%d%d",&x,&d);
            update(x,x+d-1,1,1,n,0);
        }
    }
    return 0;
}

