/****************
*PID:hdu3954
*Auth:Jonariguez
*****************
�߶���
����ά��EXP�������ֵ���ͷ�����(K��)��Ӣ�۸�����
���������Ӣ��ȫ��������ͳһά���������޸�����
���£�����˼·̫����
������hdu4027
ע�⵽�����ĳһ�����䣬����������level��ߵ���Щ��
����ά��EXP���ֵ��level���ֵ��Ȼ������updateʱֱ������
�������level��e��������������顣����add��lazy��ǡ�
�����Ǵ���ġ�����
http://blog.csdn.net/wsniyufang/article/details/6702560
Ҫ��ʹĳ������ά��ʱ�����ۼӵ����ʣ���ô���������ʲô�أ�
�������Ŀ��˵��ei����ô����Ⱥ�����ʩ��ei1��ei2ʱ�����
���α�ʩ��ʱӢ�۵�level��ͬ����ô�����ε�ei��Ӣ��������þ�
��ͬ������ei�����ǿ����ۼӵ������������ǰ������Ӣ�۵�level��ͬ
��ôei�Ϳ����ۼӣ����Ծ��뵽��ʲô����¿����ۼӣ�ʲô����²����ԡ�
���ۣ�����������ڼ��ϵ�ǰ��ei��Ȼû��Ӣ����������������ʱ����ô
���ei�Ϳ����ۼӣ���Ϊlevel*ei1+level*ei2=level*(ei1+ei2)(��Ϊû����
level���)��
��ȻҪ�жϵ�ǰ�������ei�Ƿ���Ӣ�ۻ���������Ҫά��һ����Ϣ��
��������ĳ��Ӣ�۾���������һ����Ҫ��eiֵ(���Ǿ���ֵ)����Сֵ.
�������������ǿ����ۼӵġ�
�����ǰ������Ҫ�ĸ�������Сֵ�ȵ�ǰҪʩ�ӵ�ei�������ȣ�˵����
Ӣ���������ˣ���ô��ʱ����Ҫ���¸��µ��Ǹ�Ӣ�ۣ�������������Ϊ���
�����£����������Ĳ���������ô�Ժ����ʱ����ͬ��level����ʹ��ˡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=10000+5;
const LL INF=1e18;
LL sum[maxn*4],level[maxn*4],add[maxn*4],minx[maxn*4],vis[maxn],need[12];
int K;

void pushUp(int k){
    sum[k]=max(sum[k*2],sum[k*2+1]);
    level[k]=max(level[k*2],level[k*2+1]);
    minx[k]=min(minx[k*2],minx[k*2+1]);
}

void pushDown(int k){
    int lc=k*2,rc=k*2+1;
    if(add[k]){
        sum[lc]+=level[lc]*add[k];
        sum[rc]+=level[rc]*add[k];
        add[lc]+=add[k];add[rc]+=add[k];
        minx[lc]-=add[k];minx[rc]-=add[k];
        add[k]=0;
    }
}

void build(int k,int l,int r){
    sum[k]=0;level[k]=1;
    add[k]=0;minx[k]=sum[2]/1;
    if(l==r){
      //  sum[k]=0;level[k]=1;num[k]=1;
        return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,int b,LL v,int k,int l,int r){
    int m=(l+r)/2;
    if(l==r){
        sum[k]+=level[k]*v;
        if(sum[k]>=need[K]) level[k]=K;
        else level[k]=vis[sum[k]];
        minx[k]=(need[level[k]+1]-sum[k]+level[k]-1)/level[k];
        return ;
    }
    if(a<=l && r<=b){
        if(v>=minx[k]){
            pushDown(k);
            update(a,b,v,k*2,l,m);
            update(a,b,v,k*2+1,m+1,r);
            pushUp(k);
        }else {
            add[k]+=v;sum[k]+=level[k]*v;
            minx[k]-=v;
        }
        return ;
    }
    pushDown(k);
    if(a<=m)
        update(a,b,v,k*2,l,m);
    if(b>m)
        update(a,b,v,k*2+1,m+1,r);
    pushUp(k);
}

LL ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        return sum[k];
    }
    int m=(l+r)/2;
    pushDown(k);
    LL res=0;
    if(a<=m)
        res=max(res,ask(a,b,k*2,l,m));
    if(b>m)
        res=max(res,ask(a,b,k*2+1,m+1,r));
    pushUp(k);
    return res;
}


int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",kcase++);
        scanf("%d%d%d",&n,&K,&m);
        build(1,1,n);
        memset(vis,0,sizeof(vis));
        j=0;
        for(i=2;i<=K;i++){
            scanf("%lld",&need[i]);
            for(;j<need[i];j++)
                vis[j]=i-1;
        }
        vis[j]=K;
        need[K+1]=1e18;
        char op[3];
        int l,r,e;
        while(m--){
            scanf("%s",op);
            if(op[0]=='W'){
                scanf("%d%d%d",&l,&r,&e);
                update(l,r,(LL)e,1,1,n);
            }else {
                scanf("%d%d",&l,&r);
                printf("%lld\n",ask(l,r,1,1,n));
            }
        }
        puts("");
    }
    return 0;
}



