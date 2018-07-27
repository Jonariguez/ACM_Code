/****************
*PID:hdu5634
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=300000+10;
const int maxa=10000000+2;
int phi[maxa],a[maxn];

void table(){
    phi[1]=1;
    int i,j;
    for(i=2;i<=10000000;i++){
        if(!phi[i]){
            for(j=i;j<=10000000;j+=i){
                if(!phi[j])
                    phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

typedef struct Segment{
    LL sum[maxn*4],same[maxn*4];
    void pushUp(int k){
        int lc=k*2,rc=k*2+1;
        sum[k]=sum[lc]+sum[rc];
        if(same[lc]==same[rc])
            same[k]=same[lc];
        else same[k]=0;
    }
    void pushDown(int k,int l,int r){
        if(same[k]){
            int lc=k*2,rc=k*2+1,m=(l+r)/2;
            same[lc]=same[rc]=same[k];
            sum[lc]=same[k]*(m-l+1);
            sum[rc]=same[k]*(r-m);
        }
    }
    void build(int k,int l,int r){
        sum[k]=0;
        same[k]=0;
        if(l==r){
            same[k]=(LL)a[l];
            sum[k]=same[k];
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void update(int a,int b,int k,int l,int r){
        if(l==r){
            same[k]=phi[same[k]];
            sum[k]=same[k];
            return ;
        }
        int m=(l+r)/2;
        if(a<=l && r<=b){
            if(same[k]){
                same[k]=phi[same[k]];
                sum[k]=same[k]*(r-l+1);
                return ;
            }
        }
        pushDown(k,l,r);
        if(a<=m)
            update(a,b,lson);
        if(b>m)
            update(a,b,rson);
        pushUp(k);
        return ;
    }
    void Set(int a,int b,LL v,int k,int l,int r){
        if(a<=l && r<=b){
            same[k]=v;sum[k]=v*(r-l+1);
            return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,v,lson);
        if(b>m)
            Set(a,b,v,rson);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2;
        LL res=0;
        if(a<=m)
            res+=ask(a,b,lson);
        if(b>m)
            res+=ask(a,b,rson);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m,T;
    table();
    sc(T);
    while(T--){
        sc(n);sc(m);
        for(i=1;i<=n;i++)
            sc(a[i]);
        tree.build(1,1,n);
        while(m--){
            int o,l,r;
            scanf("%d%d%d",&o,&l,&r);
            if(o==1)
                tree.update(l,r,1,1,n);
            else if(o==2){
                LL v;
                scanf("%I64d",&v);
                tree.Set(l,r,v,1,1,n);
            }else
                printf("%I64d\n",tree.ask(l,r,1,1,n));
        }
    }
    return 0;
}





