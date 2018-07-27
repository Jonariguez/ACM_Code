/*
hash + ����
���ִ𰸣������ȣ�������ֵ��
����ÿ������x��һ����n-x+1�����Ӵ�
��n-x+1���Ӵ���hashֵ�����Ƿ��ж���
�����k������ֵͬ������x���ϣ�����x��
�����Сx
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAGIC 1121117

const int maxn=20000+10;
int n,k,a[maxn];
int hash[maxn],fac[maxn],s[maxn];   //fac[i]��MAGIC^i,hash[i]��a[0]��a[i]ת����MAGIC���Ƶ�����a[0]Ȩ���

//ֱ�Ӽ���ó���a[l...r]ת����MAGIC���Ƶ���
int Get(int l,int r){
    if(l==0) return hash[r];
    return hash[r]-hash[l-1]*fac[r-l+1];
}

bool C(int x){
    int i,j,tot=0;
    for(i=0;i+x-1<n;i++){
        int v=Get(i,i+x-1);
        s[tot++]=v;
    }
    sort(s,s+tot);
    int sum=-1,now=1;
    for(i=1;i<tot;i++){
        if(s[i]==s[i-1])
            now++;
        else now=1;
        sum=max(sum,now);
    }
    return sum>=k;
}

int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    fac[0]=1;
    for(i=1;i<=n;i++)
        fac[i]=fac[i-1]*MAGIC;
    hash[0]=a[0];
    for(i=1;i<n;i++)
        hash[i]=hash[i-1]*MAGIC+a[i];
    int l=0,r=n;
    while(l<r-1){
        int m=(l+r)/2;
        if(C(m))
            l=m;
        else r=m;
    }
    printf("%d\n",l);
    return 0;
}
