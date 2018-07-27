/*
�߶��� (��ΪҪ��ɢ������������)
����ÿ���ڵ��Ӧ�����䶼Ҫ���������
��������У��±��5ȡ�������ͣ���
sum[k][0..4]���棬�ص�����������ϲ�ʱ��
���ڵ��sum[][0..4]�����������sum[][0..4]
�ֱ��Ӧ����ô����������Ķ�Ӧ��ϵȡ����
���������Ԫ�ظ�����
(��ʾ:i+5*t>cnt[k*2]+x,x���������������λ�ã�
��x=(i-cnt[k*2])%5,Ȼ��ȡ��ʹx����[0,5)����
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+5;
ll sum[maxn*4][5];
int cnt[maxn*4],a[maxn];

struct OP{
    int type,x;
}s[maxn];

void pushUp(int k){
    int lc=k*2,rc=k*2+1;
    cnt[k]=cnt[k*2]+cnt[k*2+1];
    for(int i=0;i<5;i++)
        sum[k][i]=sum[k*2][i]+sum[k*2+1][((i-cnt[k*2])%5+5)%5];
}

void build(int k,int l,int r){
    cnt[k]=0;
    for(int i=0;i<5;i++)
        sum[k][i]=0;
    if(l==r) return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void Insert(int a,int v,int k,int l,int r){
    if(l==r){
        cnt[k]++;
        sum[k][1]=v;
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,v,k*2,l,m);
    else
        Insert(a,v,k*2+1,m+1,r);
    pushUp(k);
}

void Delete(int a,int k,int l,int r){
    if(l==r){
        cnt[k]--;sum[k][1]=0;
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        Delete(a,k*2,l,m);
    else
        Delete(a,k*2+1,m+1,r);
    pushUp(k);
}

int getIndex(int x,int n){
    return (lower_bound(a,a+n,x)-a)+1;
}

int main()
{
    int i,j,n,x;
    char o[10];
    while(scanf("%d",&n)!=EOF){
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%s",o);
            if(o[0]=='a'){
                scanf("%d",&x);
                s[i].type=1;s[i].x=x;
                a[tot++]=x;
            }else if(o[0]=='d'){
                scanf("%d",&x);
                s[i].type=2;s[i].x=x;
                a[tot++]=x;
            }else
                s[i].type=3;
        }
        sort(a,a+tot);
        tot=unique(a,a+tot)-a;
        build(1,1,tot);
        for(i=0;i<n;i++){
            if(s[i].type==1)
                Insert(getIndex(s[i].x,tot),s[i].x,1,1,tot);
            else if(s[i].type==2)
                Delete(getIndex(s[i].x,tot),1,1,tot);
            else
                printf("%lld\n",sum[1][3]);
        }
    }
    return 0;
}


