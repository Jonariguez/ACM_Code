/****************
*PID:629d div2
*Auth:Jonariguez
*****************
dp[i]从1到i号圆柱能放的最大体积。(这里的号是输入的顺序)
将每个圆柱按体积排序，这样，目前处理的圆柱就可以
放在之前的所有圆柱体上，但是要最大值（用线段树维护即可）
避免精度误差，所有圆柱体积用long long 存r*r*h，最后再乘PI
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define PI acos(-1.0)
typedef long long LL;

const int maxn=100000+10;
LL dp[maxn];

struct pp{
    LL r,h,id;
    LL v;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.v==y.v)
        return x.id>y.id;   //id大的在前面，即先处理id大的，这样处理id大的时，id小的不会有影响（前提是v相等时）
    return x.v<y.v;
}

struct segment{
    LL sum[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=0LL;
        if(l==r) return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
    }
    void Insert(int p,LL v,int k,int l,int r){
        if(l==r){
            sum[k]=v;return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            Insert(p,v,k*2,l,m);
        else Insert(p,v,k*2+1,m+1,r);
        pushUp(k);
    }
    LL ask(LL a,LL b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        LL res=0LL;
        if(a<=m)
            res=max(res,ask(a,b,k*2,l,m));
        if(b>m)
            res=max(res,ask(a,b,k*2+1,m+1,r));
        return res;
    }
}tree;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&s[i].r,&s[i].h);
            s[i].v=s[i].r*s[i].r*s[i].h;
            s[i].id=i;
        }
        sort(s+1,s+n+1,cmp);
        LL res=0LL;
        tree.build(1,1,n);
        for(i=1;i<=n;i++){
            dp[i]=max(s[i].v,s[i].v+tree.ask(1,s[i].id,1,1,n));
            tree.Insert(s[i].id,dp[i],1,1,n);
        }
        for(i=1;i<=n;i++)
            res=max(res,dp[i]);
        printf("%.10f\n",(double)res*PI);
    }
    return 0;
}
