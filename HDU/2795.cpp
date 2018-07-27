/*
�߶���
��������billboard��ʱ����ת90�ȣ���ôh����߶����������䳤�ȣ���w����ÿ������ĳ�ʼֵ��
��ĿҪ���������󡱣������ϡ���ʵ���߶����о������󣬡����󡱾��ǰ��������С�
��ʵ����������߶���ά���������ֵ��Ȼ��������ֵ>wi����ݹ飬һֱ�ݹ鵽Ҷ�ӽڵ���Ǵ𰸣�
���޸Ľڵ�ֵ��Ȼ��pushUpά����  �ݹ�ʱ��ΪҪ�������������������ȵݹ顣
*/
#include <stdio.h>
#include <string.h>

const int maxn=200000+10;

int sum[maxn*4],h,n,w;

int Max(int x,int y){
    if(x<y) return y;
    return x;
}

void pushUp(int k){
    sum[k]=Max(sum[k*2],sum[k*2+1]);
}

void build(int k,int l,int r){
    if(l==r){
        sum[k]=w;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,int k,int l,int r,int W){
    if(l==r){
        sum[k]-=W;return ;
    }

}

int query(int k,int l,int r,int W){
    if(l==r){
        sum[k]-=W;return l;
    }
    int m=(l+r)/2,res;
    if(sum[k*2]>=W)
        res=query(k*2,l,m,W);
    else if(sum[k*2+1]>=W)
        res=query(k*2+1,m+1,r,W);
    else res=-1;
    pushUp(k);
    return res;
}

int main()
{
    int i,j,a,res,wi;
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        if(h>n) h=n;            //����h>nʱ��û�������ˣ���Ϊ�������һ��wi��w��Ҫ����ô�ٶ��hҲ���ܷ���
        build(1,1,h);           //���wi<=w����ôn���������Ҳ����n����λ��billboard��
        while(n--){
            scanf("%d",&wi);
            if(wi>w){
                printf("-1\n");
                continue;
            }
            printf("%d\n",query(1,1,h,wi));
        }
    }
    return 0;
}
