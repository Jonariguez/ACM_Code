/****************
*PID:hdu4027
*Auth:Jonariguez
*****************
�νⷨ��bug����Ϊ������0�Ĵ���
�����и��õĽⷨ��ά�������еķ�0��1�ĸ���num��
�޸�ʱ���������num��Ϊ0�����¸��¡�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
LL sum[maxn*4];
int n,m;

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void build(int k,int l,int r){
    sum[k]=0;
    if(l==r){
        scanf("%lld",&sum[k]);return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,int b,int k,int l,int r){
    if(a<=l && r<=b && sum[k]==r-l+1){
        return ;
    }
    if(l==r){
        sum[k]=(LL)sqrt(sum[k]+0.5);
        return ;
    }
   // pushDown(k,l,r);
  //  if(sum[k]==r-l+1) return ;
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,k*2,l,m);
    if(b>m)
        update(a,b,k*2+1,m+1,r);
    pushUp(k);
}

LL ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        return sum[k];
    }
  //  pushDown(k);
    int m=(l+r)/2;
    LL res=0;
    if(a<=m)
        res+=ask(a,b,k*2,l,m);
    if(b>m)
        res+=ask(a,b,k*2+1,m+1,r);
    pushUp(k);
    return res;
}

int main()
{
    int i,j,kcase=1;
    while(scanf("%d",&n)!=EOF){
        printf("Case #%d:\n",kcase++);
        build(1,1,n);
        scanf("%d",&m);
        int T,a,b;
        while(m--){
            scanf("%d%d%d",&T,&a,&b);
            if(a>b) swap(a,b);
            if(T==0)
                update(a,b,1,1,n);
            else printf("%lld\n",ask(a,b,1,1,n));
        }
        puts("");
    }
    return 0;
}
