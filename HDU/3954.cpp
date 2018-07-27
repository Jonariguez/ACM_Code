/****************
*PID:hdu3954
*Auth:Jonariguez
*****************
线段树
区间维护EXP经验最大值，和非满级(K级)的英雄个数，
如果该区间英雄全部满级则统一维护，否则将修改向下
更新，这种思路太慢。
类似于hdu4027
注意到如果在某一个区间，增长最快的是level最高的那些，
所以维护EXP最大值和level最大值，然后所以update时直接利用
区间最大level和e来更新区间最大经验。并用add做lazy标记。
以上是错误的。。。
http://blog.csdn.net/wsniyufang/article/details/6702560
要想使某个量在维护时具有累加的性质，那么这个量该是什么呢？
如果是题目中说的ei，那么如果先后两次施加ei1和ei2时，如果
两次被施加时英雄的level不同，那么这两次的ei对英雄起的作用就
不同，所以ei绝不是可以累加的量。但是如果前后两次英雄的level相同
那么ei就可以累加，所以就想到在什么情况下可以累加，什么情况下不可以。
结论：如果该区间在加上当前的ei依然没有英雄满足升级的条件时，那么
这个ei就可以累加，因为level*ei1+level*ei2=level*(ei1+ei2)(因为没升级
level相等)。
既然要判断当前区间加上ei是否有英雄会升级，就要维护一个信息：
该区间内某个英雄距离升到下一级需要的ei值(不是经验值)的最小值.
而这个这个量就是可以累加的。
如果当前区间需要的该量的最小值比当前要施加的ei大或者相等，说明有
英雄能升级了，那么此时就需要往下更新到那个英雄，并升级他。因为如果
不更新，本该升级的不升级，那么以后计算时按相同的level计算就错了。
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



